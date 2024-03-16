#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
map<pair<int, int>, int> cap, flow;
struct label {
    bool plus;
    int from;
    int z;
};

unordered_map<int, label> labels;
queue<int> que;

void scan(int u) {
    for(int v: graph[u]) if(labels.find(v) == labels.end()) {
        if(cap[{u, v}] - flow[{u, v}]>0) {
            labels[v] = {true, u, min(cap[{u, v}] - flow[{u, v}], labels[u].z)};
            que.push(v);
        } else if(flow[{v, u}]>0) {
            labels[v] = {false, u, min(labels[u].z, flow[{v, u}])};
            que.push(v);
        }
    }
}

bool labelandscan() {
    que = queue<int>();
    labels.clear();
    que.push(0);
    labels[0] = {true, 0, INT_MAX};
    while(!que.empty() && labels.find(401) == labels.end()) {
        scan(que.front());
        que.pop();
    }
    return labels.find(401) != labels.end();
}

int augmentflow() {
    int z = labels[401].z;
    for(int l = 401;l!=0;l = labels[l].from) {
        if(labels[l].plus) {
            flow[{labels[l].from, l}] += z;
        } else {
            flow[{l, labels[l].from}] -= z;
        }
    }
    return z;
}

void addEdge(int a, int b, int c) {
    cap[{a, b}] = c;
    graph[a].insert(b);
    graph[b].insert(a);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) addEdge(0, i, 1);
    for(int i=1;i<=m;++i) addEdge(200+i, 401, 1);

    for(int i=1, a, b;i<=n;++i) {
        cin >> a;
        while(a--) {
            cin >> b;
            addEdge(i, 200+b, 1);
        }
    }

    int ans = 0;
    while(labelandscan()) ans += augmentflow();

    cout << ans;

    return 0;
}