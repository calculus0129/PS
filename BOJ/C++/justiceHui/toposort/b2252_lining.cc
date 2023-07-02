#include <bits/stdc++.h>
using namespace std;
vector<int> g[32001];
int visited[32001];

void dfs(int node) {
    visited[node]=1;
    for(auto i:g[node]) {
        if(!visited[i]) dfs(i);
    }
    cout << node << ' ';
}

int main() {
    int m, n, a, b, i;
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    while(n--) {
        cin >> a >> b;
        g[b].push_back(a);
    }
    for(i=1;i<=m;++i) if(!visited[i]) dfs(i);
    return 0;
}