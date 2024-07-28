#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<bool> visited;



void addEdge(int a, int b) {
    g[a].push_back(b); g[b].push_back(a);
}

void dfs(int node) {
    visited[node] = true;
    for(int v: g[node]) if(!visited[v]) {
        dfs(v);
    }
}

void solve() {
    int m, n; cin >> n >> m;
    vector<bool> treasure(n+1, false);
    string s; cin >> s;
    cin >> s;
    for(int i=0;i<n;++i) if(s[i] == 'T') treasure[i+1] = true;
    g = vector<vector<int>>(n+1);
    while(m--) {
        int a, b; cin >> a >> b;
        addEdge(a, b);
    }
    visited = vector<bool>(n+1);
    for(int i=1;i<=n;++i) if(treasure[i] && !visited[i]) dfs(i);
    for(int i=1;i<=n;++i) cout << (visited[i]?'A':'B');
    cout << '\n';
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, test_case; cin >> T;
    for(test_case=0;test_case<T;++test_case) {
        cout << "Case #" << test_case+1 << '\n';
        // Print the answer
        solve();
    }
    return 0;
}