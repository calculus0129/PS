#include <bits/stdc++.h>
using namespace std;
unordered_map<int, set<int>> graph;
int vis[100100], tim;

void dfs(int node) {
    vis[node] = ++tim;
    for(int a: graph[node]) if(!vis[a]) {
        dfs(a);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n, r; cin >> m >> n >> r;
    while(n--) {
        int a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(r);
    for(int i=1;i<=m;++i) {
        cout << vis[i] << '\n';
    }


    return 0;
}