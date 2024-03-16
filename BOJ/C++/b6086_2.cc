#include <bits/stdc++.h>
using namespace std;

struct label {
    bool plus;
    char from;
    int z;
};

unordered_map<char, label> labels;
map<pair<char,char>, int> flow, cap;
unordered_map<char, unordered_set<char>> graph;
queue<char> que;

void scan(char u) {
    for(char v: graph[u]) if(labels.find(v) == labels.end()) {
        if(cap[{u, v}] - flow[{u, v}] > 0) {
            labels[v] = {true, u, min(labels[u].z, cap[{u, v}] - flow[{u, v}])};
            que.push(v);
        }
        else if(flow[{v, u}] > 0) {
            labels[v] = {false, u, min(labels[u].z, flow[{v, u}])};
            que.push(v);
        }
    }
}

bool labelandscan() {
    que = queue<char>();
    labels.clear();
    labels['A'] = label({true, 0, INT_MAX});
    que.push('A');
    while(!que.empty() && labels.find('Z')==labels.end()) {
        scan(que.front());
        que.pop();
    }
    return labels.find('Z') != labels.end();
}

int augmentflow() {
    int z = labels['Z'].z;
    for(char c = 'Z';c!='A';c = labels[c].from) {
        if(labels[c].plus) {
            flow[{labels[c].from, c}] += z;
        } else {
            flow[{c, labels[c].from}] -= z;
        }
    }
    return z;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int n, i=0;
    char a, b;
    int c;
    for(cin >> n;i<n;++i) {
        cin >> a >> b >> c;
        graph[a].insert(b);
        graph[b].insert(a);
        cap[{a, b}] += c;
        cap[{b, a}] += c;
    }

    int ans = 0;
    while(labelandscan()) {
        ans += augmentflow();
    }
    cout << ans;

    return 0;
}