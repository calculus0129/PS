#include <bits/stdc++.h>
using namespace std;

struct Solve {
	const int n;
	vector<vector<int>> graph;
	vector<bool> visited;
	vector<int> stk;
	Solve(int n)
        : n(n)	{
		graph.resize(n+1);
		//rgraph.resize(n+1);
		visited.resize(n+1);
	}
	void addEdge(int a, int b) {
		graph[a].push_back(b);
		//rgraph[b].push_back(a);
	}
	void dfs1(int u) {
		visited[u] = true;
		for(int v: graph[u]) if(!visited[v]) dfs1(v);
		stk.push_back(u);
	}
	void dfs2(int u) {
		visited[u] = false;
		for(int v: graph[u]) if(visited[v]) dfs2(v);
	}
	int main() {
		int ret = 0;
		for(int i=1;i<=n;++i) if(!visited[i]) dfs1(i);
		while(!stk.empty()) {
			int top = stk.back(); stk.erase(stk.end()-1);
			if(!visited[top]) continue;
			dfs2(top);
			++ret;
		}
		return ret;
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		Solve sol(n);
		while(m--) {
			int a, b; cin >> a >> b;
			sol.addEdge(a, b);
		}
		cout << sol.main() << '\n';
	}

	return 0;
}
