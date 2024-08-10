#include <bits/stdc++.h>
using namespace std;
// dp[i][0]: i is not usumaeul, and is ok. (have at least one usumaeul as it child)
// dp[i][1]: i is an usumaeul, and is ok. (have either 0 or 2's as each of its children.)
// dp[i][2]: i is not usumaeul, and is NOT ok. (have all 0's as each of its children.)
// Then, dp[i][0] is 
vector<int> g[10101], tree[10101];
int idx[10101], len, dp[10101][3], pop[10101];
void addEdge(int a, int b) {
	g[a].push_back(b);
	g[b].push_back(a);
}

void dfs(int u=1, int p=0) {
	for(int v: g[u]) if(v!=p) {
		tree[u].push_back(v);
		dfs(v, u);
	}
	idx[len++] = u;
}

void DP() {
	for(int i=0, u, mi;i<len;++i) {
		u = idx[i];
		dp[u][1] += pop[u];
	        mi = INT_MAX;	
		for(int v: tree[u]) {
			dp[u][1] += max(dp[v][0], dp[v][2]);
			dp[u][2] += dp[v][0];
			dp[u][0] += max(dp[v][0], dp[v][1]);
			mi = min(mi, dp[v][0]-dp[v][1]);
		}
		if(tree[u].size() && mi>0) dp[u][0] -= mi;
	}
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int a, b, n; cin >> n;
	for(int i=1;i<=n;++i) cin >> pop[i];
	for(int i=1;i<n;++i) {
		cin >> a >> b;
		addEdge(a, b);
	}
	dfs();
	DP();
	cout << max(dp[1][0], dp[1][1]);


	return 0;
}
