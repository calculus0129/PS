#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int dep[101010];
int par[18][101010];
ll cost[18][101010];
vector<vector<int>> tree;
vector<vector<pii>> graph;

void dfs1(int u = 1, int p = 0) {
	for(auto [v, w]: graph[u]) if(v!=p) {
		tree[u].push_back(v);
		dep[v] = dep[u]+1;
		par[0][v] = u;
		cost[0][v] = w; // okay!
		dfs1(v, u);
	}
}

int n;

void init() {
	for(int i=1, j;i<17;++i) for(j=1;j<=n;++j) {
		par[i][j] = par[i-1][par[i-1][j]];
		cost[i][j] = cost[i-1][j] + cost[i-1][par[i-1][j]];
	}
}

int pquery(int u, int num) {
	for(int i=0;num;++i,num>>=1) if(num&1) u = par[i][u];
	return u;
}

ll cquery(int u, int num) {
	ll ret = 0LL;
	for(int i=0;num;++i,num>>=1) if(num&1) {
		ret += cost[i][u];
		u = par[i][u];
	}
	return ret;
}

int lca(int u, int v) {
	if(dep[u]<dep[v]) swap(u, v);
	u = pquery(u, dep[u]-dep[v]);
	if(u == v) return u;
	while(par[0][u] ^ par[0][v]) {
		int j=0;
		while(par[j+1][u] != par[j+1][v]) ++j;
		u = par[j][u];
		v = par[j][v];
	}
	return par[0][u];
}

int main() {
	int u, v, k;
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	graph.resize(n+1);
	tree.resize(n+1);
	for(int i=1,w;i<n;++i) {
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}
	dfs1();
	init();
	int m, q; cin >> q;
	while(q--) {
		cin >> m >> u >> v;
		int l = lca(u, v);
		if(m == 1) {
			cout << cquery(u, dep[u] - dep[l]) + cquery(v, dep[v] - dep[l]);
		} else {
			cin >> k;
			--k;
			if(k<=dep[u]-dep[l]) cout << pquery(u, k);
			else cout << pquery(v, dep[v] - dep[l] - (k - (dep[u]-dep[l])));
		}
		cout << '\n';
	}
	return 0;
}
