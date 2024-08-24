#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

struct Solve {
	struct Edge {
		int a, b, p, q;
	};
	const int n;
	vector<vector<Edge>> graph;
	vector<bool> visited;
	vector<ll> topoOrder, masses;
	Solve(int n) : n(n) {
		graph.resize(n);
		visited.resize(n);
		masses.resize(n);
	}
	void addEdge(int a, int b, int p, int q) {
		int g = gcd(p, q);
		p/=g, q/=g;
		graph[a].push_back({a, b, p, q});
		graph[b].push_back({b, a, q, p});
	}
	void dfs1(int a=0, int from=-1) {
		for(auto [_, b, __, ___]: graph[a]) if(b!=from) {
			dfs1(b, a);
		}
		topoOrder.push_back(a);
	}
	ll mul(const Edge &e) {
		auto [a, b, p, q] = e;
		ll l = lcm(masses[a], p);
		masses[b] = q * (l / p);
		return l / masses[a];
	}
	void solve() {
		dfs1();
		reverse(ALL(topoOrder));
		fill(ALL(masses), 1LL);
		stack<int> stk;
		visited[topoOrder[0]] = true;
		for(int i=0,j;i<n;++i) {
			for(const Edge &e : graph[topoOrder[i]]) if(!visited[e.b]) {
				auto [a, b, p, q] = e;
				// cout << "Get: " << a << ' ' << b << ' ' << p << ' ' << q << '\n';
				ll m = mul(e);
				for(j=0;j<n;++j) if(visited[j]) masses[j] *= m;
				visited[b] = true;
			}
		}
		for(int m: masses) cout << m << ' ';
	}
};

int main () {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	Solve solve(n);
	while(--n) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		solve.addEdge(a, b, p, q);
	}
	solve.solve();
	return 0;
}
