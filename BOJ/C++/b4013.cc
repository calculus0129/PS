#include <bits/stdc++.h>
using namespace std;

struct Kosaraju {
	const int n;
	vector<vector<int>> graph, rgraph, sccs, scc_graph;
	vector<bool> visited, eatable, scc_eatable;
	vector<int> stk, scc_map, money, ATM;
	Kosaraju(int n): n(n) { 
		graph.resize(n+1);
		rgraph.resize(n+1);
		visited.resize(n+1);
		scc_map.resize(n+1);
		eatable.resize(n+1);
		money.resize(n+1);
	}
	void addEdge(int a, int b) 
	{
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	void dfs1(int u) {
		visited[u] = true;
		for(int v: graph[u]) if(!visited[v]) dfs1(v);
		stk.push_back(u);
	}
	void dfs2(int u, vector<int> &scc) {
		scc.push_back(u);
		visited[u] = false;
		for(int v: rgraph[u]) if(visited[v]) dfs2(v, scc);
	}
	void debug1() {
		cout << "sccs: " << sccs.size() << '\n';
		for(int i=0,m=sccs.size();i<m;++i) {
			cout << i << ": ";
			for(int u: sccs[i]) cout << u << ' ';
			cout << '\n';
		}
	}
	void debug2() {
		cout << "scc_graph:\n";
		for(int i=0,m=scc_graph.size();i<m;++i) {
			cout << i << ": ";
			for(int j: scc_graph[i]) cout << j << ' ';
			cout << '\n';
		}
		cout << "ATM:\n";
		for(int i=0,m=ATM.size();i<m;++i) {
			cout << i << ": " << ATM[i] << '\n';
		}
	}
	void make_scc_graph() {
		for(int i=1;i<=n;++i) if(!visited[i]) dfs1(i);
		while(!stk.empty()) {
			int top = stk.back(); stk.erase(stk.end()-1);
			if(!visited[top]) continue;
			vector<int> scc;
			dfs2(top, scc);
			for(int u: scc) scc_map[u] = sccs.size(); 
			sccs.push_back(scc);
		}
		int m = sccs.size();
		scc_graph.resize(m);
		scc_eatable.resize(m);
		ATM.resize(m);
		for(int i=0;i<m;++i) {
			vector<int> vis;
			vis.push_back(i);
			visited[i] = true;
			for(int u: sccs[i]) {
				ATM[i] += money[u];
				if(scc_eatable[i] != eatable[u]) scc_eatable[i] = true;
				for(int v: graph[u]) if(!visited[scc_map[v]]) {
					scc_graph[i].push_back(scc_map[v]);
					vis.push_back(scc_map[v]);
					visited[scc_map[v]] = true;
				}
			}
			for(int v: vis) visited[v] = false;
		}
	}
	int solve(int start) {
		make_scc_graph();
		//debug1();
		//debug2();
		int m = sccs.size();
		vector<int> dp(m);
		for(int i=m-1;~i;--i) {
			int a = 0;
			for(int j: scc_graph[i]) if(scc_eatable[j]) {
				scc_eatable[i] = true;
				a = max(a, dp[j]);
			}
			dp[i] = scc_eatable[i] ? ATM[i] + a : 0;
		}
		return dp[scc_map[start]];
	}
};

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int m, n; cin >> m >> n;
	Kosaraju kos(m);
	while(n--) {
		int a, b; cin >> a >> b;
		kos.addEdge(a,b);
	}
	for(int i=1;i<=m;++i) {
		cin >> kos.money[i];
	}
	int s, p; cin >> s >> p;
	while(p--) {
		int a;
		cin >> a;
		kos.eatable[a] = true;
	}
	cout << kos.solve(s);

	return 0;
}
