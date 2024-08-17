#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
struct Kosaraju {
        const int n;
        vector<vector<int>> graph, rgraph, sccs;
        vector<bool> visited;
        vector<int> stk;
        Kosaraju(int n)
        : n(n)  {
                graph.resize(n+1);
                rgraph.resize(n+1);
                visited.resize(n+1);
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
        void dfs2(int u, vector<int> &vec) {
                visited[u] = false;
                vec.push_back(u);
                for(int v: rgraph[u]) if(visited[v]) dfs2(v, vec);
        }
        void main() {
                for(int i=1;i<=n;++i) if(!visited[i]) dfs1(i);
                while(!stk.empty()) {
                        int top = stk.back(); stk.erase(stk.end()-1);
                        if(!visited[top]) continue;
                        vector<int> scc;
                        dfs2(top, scc);
			sort(ALL(scc));
                        sccs.push_back(scc);
                }
		sort(ALL(sccs), [](const vector<int> &a, const vector<int> &b) -> bool{
				return a[0] < b[0];
				});
        }
};
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	Kosaraju kos(n);
	while(m--) {
		int a, b; cin >> a >> b;
		kos.addEdge(a, b);
	}
	kos.main();
	cout << kos.sccs.size() << '\n';
	for(const vector<int> &scc: kos.sccs) {
		for(int a: scc) cout << a << ' ';
		cout << "-1\n";
	}
	return 0;
}
