#include <bits/stdc++.h>
using namespace std;

int cap[52][52], flow[52][52];
bool scanned[52];
map<char, char> prev_node;
queue<char> que;
map<char, unordered_set<char>> graph; // https://kbj96.tistory.com/23

int c_idx(char c) {
    return (c<'a')?c-'A':c-'a'+26;
}

void scan(char);
bool labelandscan();
int augmentflow();

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        char a, b; int w;
        cin >> a >> b >> w;
        cap[c_idx(a)][c_idx(b)] = cap[c_idx(b)][c_idx(a)] = cap[c_idx(a)][c_idx(b)] + w;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int value = 0;
    while(labelandscan()) {
        value += augmentflow();
    }
    cout << value;

    return 0;
}

void scan(char node) {
    scanned[c_idx(node)] = true;
    for(char v: graph[node]) if(cap[c_idx(node)][c_idx(v)]-flow[c_idx(node)][c_idx(v)]>0 && !scanned[c_idx(v)]) {
        que.push(v);
        prev_node.insert({v, node});
    }
}

// Returns true if it is the time to augment; an augmenting path has found.
bool labelandscan() {
    for(int i=0;i<52;++i) scanned[i] = false;
    que = queue<char>();
    prev_node.erase(prev_node.begin(), prev_node.end());
    que.push('A');
    while(!que.empty() && prev_node.find('Z')==prev_node.end()) {
        scan(que.front());
        que.pop();
    }
    return prev_node.find('Z')!=prev_node.end();
}

int augmentflow() {
    int f = INT_MAX;
    for(char c = 'Z';c!='A';c=prev_node[c]) {
        f = min(f, cap[c_idx(prev_node[c])][c_idx(c)] - flow[c_idx(prev_node[c])][c_idx(c)]);
    }
    for(char c = 'Z';c!='A';c=prev_node[c]) {
        flow[c_idx(prev_node[c])][c_idx(c)] += f;
        flow[c_idx(c)][c_idx(prev_node[c])] -= f;
    }
    return f;
}