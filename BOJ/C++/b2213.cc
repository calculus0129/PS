#include <bits/stdc++.h>
using namespace std;
int n, arr[10101], dp[10101][2], par[10101];
bool mx[10101];
set<int> ans;
vector<int> g[10101], tree[10101];

// init tree.
void dfs(int u=1, int p=0) {
    par[u] = p;
    for(int v: g[u]) if(v!=p) {
        tree[u].push_back(v);
        dfs(v, u);
    }
}

void DP(int u = 1) {
    int a=0, b=0;
    for(int v: tree[u]) {
        DP(v);
        a += dp[v][0];
        b += dp[v][mx[v]];
    }
    dp[u][1] = arr[u] + a;
    dp[u][0] = b;
    if(dp[u][1]>dp[u][0]) mx[u] = true;
}

void work(int u = 1, bool state = false) {
    if(!state && mx[u]) {
        ans.insert(u);
        for(int v: tree[u]) work(v, true);
    } else {
        for(int v: tree[u]) work(v, false);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;++i) cin >> arr[i];
    for(int i=0, a, b;i<n-1;++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    DP();
    work();
    cout << max(dp[1][0], dp[1][1]) << '\n';
    for(int i: ans) cout << i << ' ';

    return 0;
}