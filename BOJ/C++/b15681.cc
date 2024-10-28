#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph, tree;
vector<int> toposort;
vector<bool> visited;
vector<int> dp;
void addEdge(int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void dfs(int node) {
    visited[node] = true;
    for(int v: graph[node]) if(!visited[v]) {
        tree[node].push_back(v);
        dfs(v);
    }
    toposort.push_back(node);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int r, q;
    cin >> n >> r >> q;
    graph.resize(n+1);
    tree.resize(n+1);
    visited.resize(n+1);
    int a, b;
    for(int i=1;i<n;++i) {
        cin >> a >> b;
        addEdge(a, b);
    }
    dfs(r);
    dp.resize(n+1);
    for(int u: toposort) {
        for(int v: tree[u]) dp[u] += dp[v];
        dp[u]++;
    }
    while(q--) {
        cin >> a;
        cout << dp[a] << '\n';
    }
    return 0;
}