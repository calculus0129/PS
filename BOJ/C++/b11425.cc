#include <bits/stdc++.h>
using namespace std;
struct Node {
    bool terminal;
    map<char, Node*> children; 
    Node()
    : terminal(false) {}
};

class Trie {
    public:
    Node *node;
    Trie() 
    : node(new Node()) {}
    void insert(const string &key) {
        Node *tgt = node;
        int n = key.size();
        for(int i=0;i<n;++i) {
            if(tgt->children[key[i]] == NULL) tgt->children[key[i]] = new Node();
            tgt = tgt->children[key[i]];
        }
        tgt->terminal = true;
    }
    bool find(const string &key) {
        Node *tgt = node;
        int n = key.size();
        for(int i=0;i<n;++i) {
            tgt = tgt->children[key[i]];
            if(tgt == NULL) return false;
        }
        return tgt->terminal;
    }
};

int main() {
    int m, n;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    Trie trie;
    for(int i=0;i<n;++i) {
        string s;
        cin >> s;
        trie.insert(s);
    }
    int cnt = 0;
    for(int i=0;i<m;++i) {
        string s;
        cin >> s;
        if(trie.find(s)) ++cnt;
    }
    cout << cnt;
    return 0;
}