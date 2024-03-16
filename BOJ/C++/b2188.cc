#include <bits/stdc++.h>
using namespace std;
int n, m;

map<pair<int,int>, int> flow, cap;
map<int, unordered_set<int>> graph;
queue<int> que;

struct label {
    int prev;
    bool plus;
    int z;
};

map<int, label> labels;

void addedge(int a, int b, int c=1) {
    cap[{a, b}] = c;
    flow[{a, b}] = 0;
    graph[a].insert(b);
    graph[b].insert(a);
}

void scan(int node) {
    for(int v: graph[node]) if(labels.find(v)==labels.end()) {
        if(cap[{node, v}]-flow[{node, v}]>0) {
            labels[v] = label({node, true, min(labels[node].z, cap[{node, v}]-flow[{node, v}])});
            que.push(v);
        }
        else if(flow[{v, node}]>0) {
            labels[v] = label({node, false, min(labels[node].z, flow[{v, node}])});
            que.push(v);
        }
    }
}

bool labelandscan() {
    que = queue<int>();
    labels.clear();
    que.push(0);
    labels[0] = label({-1, true, INT_MAX});
    while(!que.empty() && labels.find(401)==labels.end()) {
        scan(que.front());
        que.pop();
    }
    return labels.find(401) != labels.end();
}

int augmentflow() {
    int ret = labels[401].z;
    for(int v = 401;v!=0;v = labels[v].prev) {
        if(labels[v].plus) {
            flow[{labels[v].prev, v}]+=ret;
        } else {
            flow[{v, labels[v].prev}]-=ret;
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        addedge(0, i);
    }
    for(int i=1;i<=m;++i) {
        addedge(200+i, 401);
    }

    for(int i=1, num, a;i<=n;++i) {
        for(cin >> num;num>0;--num) {
            cin >> a;
            addedge(i, 200+a);
        }
    }
    int ans=0;
    while(labelandscan()) ans += augmentflow();
    cout << ans;
    return 0;
}