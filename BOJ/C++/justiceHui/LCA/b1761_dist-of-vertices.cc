// 이는 일단, 우리가 root를 1로 봐도 무방하다.
// option 1: 거리를 par배열과 비슷하게 저장한다.
// option 2: 거리를 DFS하면서 root로부터의 거리를 구하고 두 정점 u, v이 주어지면 LCA l를 구하고 dist[u]+dist[v]-2*dist[l]을 출력시킨다.
// 한번 option1으로 해보자. 구현이 사알짝 더 challenging할 것 같으니.
// 참고로 option2가 거리 구하는 데 O(N), option1의 경우 N개의 nodes에 대해 logN 정도 깊이의 par 배열을 저장하므로 O(NlogN)이므로 option2가 시복은 더 낫긴 하다.

#include <bits/stdc++.h>
using namespace std;
const int SIZ=40010;
int n;

struct edge {
    int to, len;
};

vector<edge> g[SIZ];
int par[SIZ][16], dist[SIZ][16], depth[SIZ];
bool visited[SIZ];

void dfs_init(int node, int d) {
    visited[node]=1;
    depth[node]=d;
    for(const auto &i: g[node]) if(!visited[i.to]) {
        par[i.to][0]=node;
        dist[i.to][0]=i.len;
        dfs_init(i.to, d+1);
    }
}

void make_table() {
    for(int i=1,j;i<16;++i) for(j=1;j<=n;++j) {
        par[j][i]=par[par[j][i-1]][i-1];
        dist[j][i]=dist[j][i-1]+dist[par[j][i-1]][i-1];
    }
}

int ith_par(int node, int idx) {
    int ret = node, i=0;
    do {
        if(idx&1) ret = par[ret][i];
        ++i;
    } while(idx>>=1);
    return ret;
}

void lca(int u, int v, int *arr) {
    arr[0]=arr[1]=0;
    if(depth[u]<depth[v]) {
        arr[1]=depth[v]-depth[u];
        v = ith_par(v, depth[v]-depth[u]);
    } else if(depth[u]>depth[v]) {
        arr[0]=depth[u]-depth[v];
        u = ith_par(u, depth[u]-depth[v]);
    }
    int d = 0, i=16;
    if(v==u);
    else {
        while(--i>=0) if(par[u][i]!=par[v][i]) {
            d|=1<<i;
            u = par[u][i];
            v = par[v][i];
        }
        ++d;
    }
    arr[0]+=d;
    arr[1]+=d;
}

int dist2ith_par(int node, int idx) {
    int ret=0, p=node, i=0;
    do {
        if(idx&1) {
            ret+=dist[p][i];
            p = par[p][i];
        }
        ++i;
    } while(idx>>=1);
    return ret;
}

// par[i][j]: node i의 2^j번째 parent
// dist[i][j]: node i의 2^j번째 parent까지의 거리


// 생각해보자.
// par 배열(LCA?)는 일단 만드는 데 공복,시복은 O(NlogN)이다.
// 이를 만들어두면 어떤 node라도 n번째 parent를 logn의 참조만으로 찾을 수 있다.
// 마치 exponentiation by squaring에서 몇의 2^j제곱의 mod를 저장해두고 1인 비트에 해당하는 제곱수들을 곱하는 느낌으로,
// par를 저장해두고 1인 비트 자리수에 해당하는 par node를 따라 가면 된다.
// 그러면 어떻게 하지? 처음 1을 root로 잡고 par[i][0]들을 dfs로 초기화할 때 동시에 root로부터의 경로의 길이(경로상의 edge 개수) depth배열도 초기화한다.
// depth가 같을 때까지 둘 중 작은 걸 위로 올리고, ㅇㅇ
// 그러면 LCA까지 몇 째 par인지를 구한다.
// 그것을 통해 dist배열로부터 이것저것을 더해서 원하는 거리를 구할 수 있다.

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, d, i, j, k;
    cin >> n;

    i=0;
    while(++i<n) {
        cin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }
    dfs_init(1, 0);
    make_table();
    int m, arr[2];
    cin >> m;
    while(m--) {
        cin >> a >> b;
        lca(a, b, arr);
        cout << dist2ith_par(a, arr[0]) + dist2ith_par(b, arr[1]) << '\n';
    }

    return 0;
}