#include <bits/stdc++.h>
using namespace std;
struct Solve {
	const int n;
	vector<vector<int>> graph, rgraph;
	vector<bool> visited;
	vector<int> stk;
	Solve(int n)
	: n(n) {
		graph.resize(n); rgraph.resize(n);
		visited.resize(n);
	}
	void addEdge(int a, int b) {
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	void dfs1(int u) {
		visited[u] = true;
		for(int v: graph[u]) if(!visited[v]) dfs1(v);
		stk.push_back(u);
	}
	int dfs2(int u) {
		int ret = 1;
		visited[u] = false;
		for(int v: graph[u]) if(visited[v]) ret += dfs2(v);
		return ret;
	}
	void dfs3(int u, vector<int> &scc) {
		visited[u] = true;
		scc.push_back(u);
		for(int v: rgraph[u]) if(!visited[v]) dfs3(v, scc);
	}
	bool possible() {
		return dfs2(stk.back()) == n;
	}

	vector<int> main() {
		vector<int> ret;
		for(int i=0;i<n;++i) if(!visited[i]) dfs1(i);
		if(!possible()) return ret;
		dfs3(stk.back(), ret);
		sort(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		int m, n; cin >> m >> n;
		Solve sol(m);
		while(n--) {
			int a, b; cin >> a >> b;
			sol.addEdge(a, b);
		}
		vector<int> ans = sol.main();
		if(ans.empty()) cout << "Confused\n";
		else for(int u: ans) cout << u << '\n';
		cout << '\n';
	}
	return 0;
}
