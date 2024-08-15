#include <bits/stdc++.h>
using namespace std;
int par[10101][15], depth[10101];
vector<vector<int>> tree;

void dfs(int u) {
	for(int v: tree[u]) {
		depth[v] = depth[u]+1;
		dfs(v);
	}
}

int lca(int u, int v) {
	if(depth[u]<depth[v]) swap(u,v);
	for(int a=depth[u]-depth[v],i=0;a;a>>=1,++i) {
		if(a&1) u = par[u][i];
	}
	if(u == v) return u;
	for(int j=0;;u=par[u][j],v=par[v][j],j=0) {
		while(par[u][j] != par[v][j]) ++j;
		--j;
		if(!~j) break;
	}
	return par[u][0];
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		tree.clear(); tree.resize(n+1);
		for(int i=1;i<=n;++i) par[i][0] = 0;
		for(int a,b,_=1;_<n;++_) {
			cin >> a >> b;
			par[b][0] = a;
			tree[a].push_back(b);
		}
		for(int i=1,j;i<14;++i) for(j=1;j<=n;++j) par[j][i] = par[par[j][i-1]][i-1];
		int root=1, qx, qy;
		for(;root<=n && par[root][0];++root);
		depth[root] = 0;
		dfs(root);
		cin >> qx >> qy;
		cout << lca(qx,qy) << '\n';
	}
	return 0;
}
