#include <bits/stdc++.h>
using namespace std;
// int par[7][101];
vector<vector<int>> graph;
bool visited[101];
int x, y;

int dfs(int node, int from=-1, int dist=0) {
    if(node == y) return dist;
    visited[node] = true;
    int ret=-1;
    for(int nxt: graph[node]) if(nxt!=from) {
        ret = dfs(nxt, node, dist+1);
        if(ret>=0) break;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    graph.resize(n+1);
    cin >> x >> y;
    int m; cin >> m;
    int a, b;
    while(m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        // par[0][b] = a;
    }
    // for(int i=1, j;i<7;++i) {
    //     for(j=1;j<=n;++j) if(par[i-1][n]) {
    //         par[i][n] = par[i-1][par[i-1][n]];
    //     }
    // }
    cout << dfs(x);

    return 0;
}