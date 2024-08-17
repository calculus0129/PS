#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int n;
vector<vector<int>> graph, rgraph;
vector<int> stk;
bool visited[10001];

void dfs1(int u) {
	visited[u] = true;
	for(int v: graph[u]) if(!visited[v]) dfs1(v);
	stk.push_back(u);
}

void dfs2(int u, vector<int> &vec) {
	visited[u] = false;
	vec.push_back(u);
	for(int v: rgraph[u]) if(visited[v]) dfs2(v, vec);
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int e; cin >> n >> e;
	graph.resize(n+1);
	rgraph.resize(n+1);
	vector<vector<int>> sccs;
	while(e--) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	for(int i=1;i<=n;++i) if(!visited[i]) dfs1(i);
	while(!stk.empty()) {
		int top = stk.back(); stk.erase(stk.end()-1);
		if(!visited[top]) continue;
		vector<int> scc;
		dfs2(top, scc);
		sort(ALL(scc));
		sccs.push_back(scc);
	}
	sort(ALL(sccs), [](const vector<int> &a, const vector<int> &b) -> bool {
		return a[0]<b[0];
	});
	e = sccs.size();
	cout << e << '\n';
	for(int i=0;i<e;++i) {
		for(auto it=sccs[i].begin(), eit=sccs[i].end();it!=eit;it++) cout << *it << ' ';
		cout << "-1\n";
	}
	return 0;
}
