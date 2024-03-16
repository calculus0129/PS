#include <bits/stdc++.h>
using namespace std;
int n;
map<int, unordered_set<int>> graph;
queue<int> que;

struct label {
    int from;
    bool plus;
    int z;
};

map<int, label> labels;
map<pair<int, int>, int> cap, flow;
set<int> scanned;

void add_unit_edge(int a, int b, int c=1) {
    cap[make_pair(a, b)]=c;
    graph[a].insert(b);
    graph[b].insert(a);
}

void initnode(int node) {
    add_unit_edge(-node, node);
}

void addEdge(int a, int b, int c=1) {
    add_unit_edge(a, -b, c);
    add_unit_edge(b, -a, c);
}

void scan(int node) {
    for(int v: graph[node]) if(labels.find(v)==labels.end()) {
        if(cap[{node, v}]-flow[{node, v}]>0) {
            labels[v] = label({node, true, min(labels[node].z, cap[{node, v}]-flow[{node, v}])});
            que.push(v);
        } else if(flow[{v, node}]>0) {
            labels[v] = label({node, false, min(labels[node].z, flow[{v, node}])});
            que.push(v);
        }
    }
    scanned.insert(node);
}

bool labelandscan() {
    que = queue<int>();
    scanned.clear();
    labels.clear();
    labels.insert({1, label({0, true, INT_MAX})});
    que.push(1);
    while(!que.empty() && labels.find(-2) == labels.end()) {
        scan(que.front());
        que.pop();
    }
    return labels.find(-2) != labels.end();
}

int augmentflow() {
    int ret = labels[-2].z;
    for(int v=-2;labels[v].from!=1;v=labels[v].from) {
        if(labels[v].plus) {
            flow[{labels[v].from, v}]+=ret;
        } else {
            flow[{v, labels[v].from}]-=ret;
        }
    }
    return ret;
}

int main() {
    int p;
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;++i) initnode(i);
    for(cin>>p;p>0;--p) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
    int ans=0;
    while(labelandscan()) ans += augmentflow();
    cout << ans;
    return 0;
}

/*
17 19
1 4
1 5
3 12
3 2
4 3
4 8
5 6
6 7
7 3
8 9
9 10
10 11
11 15
12 13
14 11
14 15
15 16
16 17
17 2
ANS 2
*/