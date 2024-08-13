#include <bits/stdc++.h>
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;

vector<string> dict;
map<string,int> idx;

class Node {
    public:
    bool terminal;
    map<int,Node*> children;
    Node() {
        terminal = false;
    }
};

class Trie {
    public:
    Node *node;
    Trie(Node *node = NULL)
    : node{node} {
        // if(node == NULL) node = new Node(); // This is LOCAL VARIABLE node.
        if(node == NULL) this->node = new Node();
    }
    void insert(const vector<int> &key) {
        Node *tgt = node;
        for(int i=0,n=key.size();i<n;++i) {
            if(tgt->children[key[i]] == NULL) tgt->children[key[i]] = new Node();
            tgt = tgt->children[key[i]];
        }
        tgt->terminal = true;
    }
};

void dfs(const Node *node, int depth = 0) {
    int j=0;
    for(const auto [i, nxt]: node->children) {
        for(j=0;j<depth;++j) cout << "--";
        cout << dict[i] << '\n';
        if(nxt!=NULL) dfs(nxt, depth+1);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<string>> inp(n);
    for(int i=0,k,j;i<n;++i) {
        cin >> k; inp[i].resize(k);
        for(j=0;j<k;++j) {
            cin >> inp[i][j];
            dict.push_back(inp[i][j]);
        }
    }
    sort(ALL(dict)); dict.erase(unique(ALL(dict)), END(dict));
    n = dict.size();
    for(int i=0;i<n;++i) {
        idx[dict[i]] = i;
        // cout << i << ": " << dict[i] << '\n';
    }
    Trie trie;

    for(const vector<string> &vec: inp) {
        n = vec.size();
        vector<int> seq(n);
        for(int i=0;i<n;++i) {
            seq[i] = idx[vec[i]];
        }
        trie.insert(seq);
    }

    dfs(trie.node);

    return 0;
}