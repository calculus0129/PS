#include <bits/stdc++.h>
using namespace std;
const int siz = 1e5+10;
vector<int> g[siz];
// par[i][j]: node i의 2^j번째 parent
int visited[siz], depth[siz], par[siz][18];
int n;

void dfs(int node, int d) {
    visited[node]=1;
    depth[node]=d;
    for(auto &i: g[node]) if(!visited[i]) {
        par[i][0]=node;
        dfs(i, d+1);
    }
}

void update_table() {
    for(int i=1,j;i<=16;++i) {
        for(j=1;j<=n;++j) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v) {
    int i;
    if(depth[u]<depth[v]) swap(u, v);
    int dif = depth[u]-depth[v];
    i=0;
    while(dif) {
        if(dif&1) {
            u = par[u][i];
        }
        ++i;
        dif>>=1;
    }
    if(u==v) return u;
    for(i=16;i>=0;--i) if(par[u][i]!=par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i=n, a, b;
    while(--i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    update_table();
    int m; cin >> m;
    while(m--) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}