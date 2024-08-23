#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

struct Kosaraju {
    const int n;
    int m;
    vector<vector<int>> g, rg, scc_set;
    vector<set<int>> scc_rg, scc_g;
    vector<int> scc_map, stk, interest, scc_int, dp;
    vector<bool> visited, banned;
    Kosaraju(int n) : n(n), m(0) {
        g.resize(n+1);
        rg.resize(n+1);
        visited.resize(n+1);
        scc_map.resize(n+1);
        interest.resize(n+1);
    }
    void addEdge(int a, int b) {
        // b is required for a
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    void dfs1(int u) {
        visited[u] = true;
        for(int v: g[u]) if(!visited[v]) dfs1(v);
        stk.push_back(u);
    }
    void dfs2(int u, int scc) {
        visited[u] = false;
        scc_map[u] = scc;
        scc_set[scc].push_back(u);
        scc_int[scc] += interest[u];
        for(int v: rg[u]) {
            if(visited[v]) dfs2(v, scc);
            else {
                scc_rg[scc].insert(scc_map[v]);
                scc_g[scc_map[v]].insert(scc);
            }
        }
    }
    void dfs3(int u) {
        banned[u] = true;
        for(int v: scc_rg[u]) if(!banned[v]) dfs3(v);
    }
    void findScc() {
        for(int i=1;i<=n;++i) if(!visited[i]) dfs1(i);
        while(!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            if(visited[u]) {
                scc_set.push_back(vector<int>());
                scc_rg.push_back(set<int>());
                scc_g.push_back(set<int>());
                scc_int.push_back(0);
                dfs2(u, m++);
            }
        }
    }
    void solve() {
        findScc();
        banned.resize(m);
        dp.resize(m);
        int ans = 0;
        bool r = true;
        while(r) {
            r = false;
            for(int i=0;i<m;++i) if(!banned[i]) {
                dp[i] = scc_int[i];
                for(int j: scc_rg[i]) if(!banned[j]) {
                    dp[i] += dp[j];
                }
                if(dp[i] <= 0) {
                    dfs3(i);
                    r = true;
                    break;
                }
            }
        }
        for(int i=0;i<m;++i) if(!banned[i]) ans += scc_int[i];
        cout << ans << '\n';
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        Kosaraju k(n);
        for(int i=1;i<=n;++i) {
            cin >> k.interest[i];
        }
        for(int i=1,a,j;i<=n;++i) {
            cin >> a;
            while(a--) {
                cin >> j;
                k.addEdge(i, j);
            }
        }
        k.solve();
    }
    return 0;
}