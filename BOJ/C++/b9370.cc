#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, t, s, g, h;
typedef pair<int,int> pii;
typedef tuple<int,int,bool> tup;
unordered_map<int, vector<pii>> graph;
unordered_set<int> candidates;
set<int> ans;
struct cmp {
	bool operator() (const tup &a, const tup &b) {
		return get<1>(a)==get<1>(b) ? get<2>(b) : get<1>(a)>get<1>(b);
	}
};
priority_queue<tup, vector<tup>, cmp> pq;

void addEdge(int a, int b, int c) {
	graph[a].push_back({b, c});	
	graph[b].push_back({a, c});
}

bool matches(int a, int b) {
	return a == g && b == h || a == h && b == g;
}

void dijkstra() {
	unordered_map<int,int> dist;
	pq.push({s, 0, false});
	int to, d;
	bool smelly;
	while(!pq.empty()) {
		tie(to, d, smelly) = pq.top(); pq.pop();
		if(dist.find(to) != dist.end()) continue;
		dist[to] = d;
		if(smelly && candidates.find(to) != candidates.end()) ans.insert(to);
		for(auto [dest, cost] : graph[to]) if(dist.find(dest) == dist.end()) {
			pq.push({dest, d + cost, smelly || matches(to, dest)});
		}		
	}
}

void solve() {
	ans.clear(); candidates.clear();
	graph.clear();
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	int a, b, c;
	while(m--) {
		cin >> a >> b >> c;
		addEdge(a, b, c);
	}
	while(t--) {
		cin >> c;
		candidates.insert(c);
	}
	dijkstra();
	for(int s: ans) cout << s << ' ';
	cout << '\n';
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
