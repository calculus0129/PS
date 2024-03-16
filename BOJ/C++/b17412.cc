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

int cap[401][401], flow[401][401];
bool scanned[401];

void addEdge(int a, int b, int c=1) {
    cap[a][b]=c;
    graph[a].insert(b);
    graph[b].insert(a);
}

void scan(int node) {
    for(int v: graph[node]) if(labels.find(v)==labels.end()) {
        if(cap[node][v]-flow[node][v]>0) {
            labels[v] = label({node, true, min(labels[node].z, cap[node][v]-flow[node][v])});
            que.push(v);
        } else if(flow[v][node]>0) {
            labels[v] = label({node, false, min(labels[node].z, flow[v][node])});
            que.push(v);
        }
    }
    scanned[node]=true;
}

bool labelandscan() {
    que = queue<int>();
    fill(scanned, scanned+401, false);
    labels.clear();
    labels.insert({1, label({-1, true, INT_MAX})});
    que.push(1);
    while(!que.empty() && labels.find(2) == labels.end()) {
        scan(que.front());
        que.pop();
    }
    return labels.find(2) != labels.end();
}

int augmentflow() {
    int ret = labels[2].z;
    for(int v=2;labels[v].from!=-1;v=labels[v].from) {
        if(labels[v].plus) {
            flow[labels[v].from][v]+=ret;
        } else {
            flow[v][labels[v].from]-=ret;
        }
    }
    return ret;
}

int main() {
    int p;
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
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