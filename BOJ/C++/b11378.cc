#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, flow;
    };
    int m;
    vector<vector<int>> adj;
    vector<Edge> edges;
    vector<int> level, ptr;
    const int src = 0, sink = 2001;
    Dinic() : m(0) {
        adj.resize(2003);
    }
    void addEdge(int a, int b, int c) {
        adj[a].push_back(m);
        edges.push_back({b, c, 0});
        adj[b].push_back(m + 1);
        edges.push_back({a, 0, 0});
        m += 2;
    }
    bool bfs() {
        level.assign(2003, -1);
        level[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for(int i: adj[a]) if(!~level[edges[i].to] && edges[i].cap > edges[i].flow) {
                level[edges[i].to] = level[a] + 1;
                q.push(edges[i].to);
            }
        }
        return ~level[sink];
    }
    int dfs(int a, int z) {
        if(!z || a == sink) return z;
        for(int &ci = ptr[a],sz=adj[a].size(),i;ci<sz;++ci) {
            i = adj[a][ci];
            Edge &e = edges[i];
            if(level[e.to] == level[a] + 1 && e.cap > e.flow) {
                int x = dfs(e.to, min(z, e.cap - e.flow));
                if(x) {
                    e.flow += x;
                    edges[i ^ 1].flow -= x;
                    return x;
                }
            }
        }
        return 0;
    }
    int maxFlow() {
        int flow = 0;
        while(bfs()) {
            ptr.assign(2003, 0);
            while(int x = dfs(src, INT_MAX)) flow += x;
        }
        return flow;
    }
};

// https://justicehui.github.io/ps/2019/03/17/BOJ11378/
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    Dinic dinic;
    dinic.addEdge(0, 2002, k);
    for(int i=1, a, w;i<=n;++i) {
        dinic.addEdge(0, i, 1);
        dinic.addEdge(2002, i, k+1);
        cin >> a;
        while(a--) {
            cin >> w;
            dinic.addEdge(i, 1000+w, 1);
        }
    }
    for(int i=1;i<=m;++i) dinic.addEdge(1000+i, 2001, 1);
    cout << dinic.maxFlow();

    return 0;
}