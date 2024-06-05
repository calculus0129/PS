#include <bits/stdc++.h>
using namespace std;
int n, k, d;

struct label {
    bool plus;
    int from, z;
};

set<int> graph[304];
int cap[304][304], flow[304][304];
label labels[304];

void addEdge(int a, int b, int c) {
    cap[a][b] = c;
    graph[a].insert(b);
    graph[b].insert(a);
}

void input() {
    cin >> n >> k >> d;
    for(int i=1;i<=n;++i) addEdge(0, i, k);
    for(int i=1, a;i<=d;++i) {
        cin >> a;
        addEdge(200+i, 301, a);
    }
    for(int i=1, a, b, j;i<=n;++i) {
        cin >> a;
        for(j=0;j<a;++j) {
            cin >> b;
            addEdge(i, 200+b, 1);
        }
    }
}

queue<int> que; // the vertex number of unscanned, labeled vertex neighboring to a scanned one.

void scan(int u) {
    int z;
    for(int v: graph[u]) if(labels[v].z==0) {
        z=min(labels[u].z, cap[u][v]-flow[u][v]);
        if(z>0) {
            labels[v]={true, u, z};
            que.push(v);
        }
        else if((z=min(labels[u].z, flow[v][u]))>0) {
            labels[v]={false, u, z};
            que.push(v);
        }
    }
}

// returns if the sink is labeled or not.
bool labelandscan() {
    memset(labels, 0, sizeof(labels));
    que = queue<int>();
    labels[0] = {true, -1, 1000};
    que.push(0);
    while(!que.empty() && labels[301].z==0) {
        int u = que.front();que.pop();
        scan(u);
    }
    return labels[301].z!=0;
}

// returns the added flow of the flow augment path.
int augment() {
    int z = labels[301].z;
    for(int v = 301, u;v!=0;v=u) {
        u = labels[v].from;
        if(labels[v].plus) {
            flow[u][v] += z;
        }
        else {
            flow[v][u] -= z;
        }
    }
    return z;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    // ford_fulkerson;
    int ans = 0;
    while(labelandscan()) {
        ans += augment();
    }
    cout << ans;
    return 0;
}