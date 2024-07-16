#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[1000100][2]; // dp[i][j]: i번 정점을 루트로 하는 subtree에 대해 i가 [얼리 어뎁터가 아닐때/맞을때] 필요한 최소 얼리 어뎁터수.
// dp[바닥][0] = INT_MAX
// dp[바닥][1] = 1
// dp[i][0] = 각각의 children v에 대해 dp[v][1]의 총합.
// dp[i][1] = dp[v][0], dp[v][1] 중 최솟값들의 총합에 1 추가.
int n;

vector<unordered_set<int>> g;
// unordered_set<int> visited;

// make the graph to tree, and get parent information, if necessary.
void dfs(int u=1, int p = -1) {
    if(g[u].find(p) != g[u].end()) g[u].erase(g[u].find(p));
    for(int v: g[u]) {
        // par[v] = u;
        dfs(v, u);
    }
}

void DP(int u = 1) {
    ll a = 0LL, b = 1LL; // Because N!=1, we may set a as 0 initially. => This does not affect the root's behavior.
    if(!g[u].empty()) {
        for(int v: g[u]) {
            DP(v);
            a += dp[v][1];
            b += min(dp[v][0], dp[v][1]);
        }
    }
    dp[u][0] = a;
    dp[u][1] = b;
}

// cf. https://www.acmicpc.net/source/share/d61d169e421b471e9bcbe682116e313e

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    g.resize(n+1);
    int a, b;
    for(int i=0;i<n-1;++i) {
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    dfs();
    DP();
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}