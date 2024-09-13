#include <bits/stdc++.h>
using namespace std;
int m, n, r, tim;
int ans[100100];
map<int,priority_queue<int>> g;
void dfs(int node) {
    ans[node] = ++tim;
    while(!g[node].empty()) {
        int top = g[node].top(); g[node].pop();
        if(!ans[top]) dfs(top);
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n >> r;
    while(n--) {
        int a, b; cin >> a >> b;
        g[a].push(b);
        g[b].push(a);
    }
    dfs(r);
    for(int i=1;i<=m;++i) cout << ans[i] << '\n';

    return 0;
}