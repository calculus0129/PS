#include <bits/stdc++.h>
const int SIZE=101010;
using namespace std;
typedef pair<int,int> pii;
int visited[SIZE], n, par[17][SIZE], mn[17][SIZE], mx[17][SIZE], depth[SIZE];
vector<pii> g[SIZE];

void dfs_init(int node, int d) {
    visited[node]=1;
    depth[node]=d;
    for(const pii &i:g[node]) if(!visited[i.first]) {
        par[0][i.first]=node;
        mn[0][i.first]=mx[0][i.first]=i.second;
        dfs_init(i.first, d+1);
    }
}

void make_table() {
    int i=0, j;
    while(++i<17) for(j=1;j<=n;++j) {
        par[i][j] = par[i-1][par[i-1][j]];
        mn[i][j] = min(mn[i-1][j], mn[i-1][par[i-1][j]]);
        mx[i][j] = max(mx[i-1][j], mx[i-1][par[i-1][j]]);
    }
}

int ith_parent(int node, int idx) {
    int p=node, i=0;
    do {
        if(idx&1) p=par[i][p];
        ++i;
    } while(idx>>=1);
    return p;
}

void lca(int u, int v, int *arr) {
    arr[0]=arr[1]=0;
    if(depth[u]<depth[v]) v = ith_parent(v, arr[1]=depth[v]-depth[u]);
    else if(depth[u]>depth[v]) u = ith_parent(u, arr[0]=depth[u]-depth[v]);
    if(u==v) return;
    int i=17, d=0;
    while(--i>=0) if(par[i][u]!=par[i][v]) {
        d |= 1<<i;
        // Therefore, u != v. But their parents are the same.
        u = par[i][u];
        v = par[i][v];
    }
    ++d;
    arr[0]+=d;
    arr[1]+=d;
}

int ith_mn(int node, int idx) {
    int ret=1000001, p=node, i=0;
    do {
        if(idx&1) {
            ret = min(ret, mn[i][p]);
            p=par[i][p];
        }
        ++i;
    } while(idx>>=1);
    //if(p==1000001) return 0;
    return ret;
}

int ith_mx(int node, int idx) {
    int ret=0, p=node, i=0;
    do {
        if(idx&1) {
            ret = max(ret, mx[i][p]);
            p=par[i][p];
        }
        ++i;
    } while(idx>>=1);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i=n-1, a, b, c, m, arr[2];
    while(i--) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    mn[0][1]=1000001;
    mx[0][1]=0;
    dfs_init(1, 0);
    make_table();
    cin >> m;
    while(m--) {
        cin >> a >> b;
        lca(a, b, arr);
        cout << min(ith_mn(a, arr[0]), ith_mn(b, arr[1])) << ' ';
        cout << max(ith_mx(a, arr[0]), ith_mx(b, arr[1])) << '\n';
    }

    return 0;
}