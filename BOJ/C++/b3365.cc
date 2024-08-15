#include <bits/stdc++.h>
using namespace std;
vector<set<int>> graph;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	int arr[501];
	while(T--) {
		int a, b, n, m; cin >> n;
		graph.clear(); graph.resize(n+1);
		for(int i=0;i<n;++i) {
			cin >> arr[i];
		}
		for(int i=0,j;i<n-1;++i) {
			for(j=i+1;j<n;++j) {
				graph[arr[i]].insert(arr[j]);
			}
		}
		cin >> m;
		while(m--) {
			cin >> a >> b;
			if(graph[a].find(b) == graph[a].end()) swap(a, b);
			graph[a].erase(b);
			graph[b].insert(a);
		}
		memset(arr,0,sizeof(arr));
		bool r = true;
		for(int i=1;i<=n;++i) {
			if(arr[graph[i].size()]) {
				r = false;
				break;
			}
			arr[graph[i].size()] = i;
		}
		if(r) {
			for(int i=n-1;~i;--i) cout << arr[i] << ' ';
			cout << '\n';
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}
