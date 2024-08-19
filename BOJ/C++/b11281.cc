#include <bits/stdc++.h>
using namespace std;

struct SAT2 {
    const int n;
    int m;
    vector<vector<int>> g, rg, sccs;
    vector<int> sccMap, stk;
    vector<bool> vis;
    SAT2(int n)
    : n(n), m(0) {
        int num = (n+1)<<1;
        g.resize(num);
        rg.resize(num);
        sccMap.resize(num);
        vis.resize(num);
    }
    int vtx(int literal) {
        return abs(literal)<<1|(literal<0);
    }
    int lit(int vertex) {
        return (vertex>>1) * (vertex&1?-1:1);
    }
    void addClause(int a, int b) {
        int na = vtx(-a), nb = vtx(-b);
        a = vtx(a), b = vtx(b);
        g[na].push_back(b);
        g[nb].push_back(a);
        rg[a].push_back(nb);
        rg[b].push_back(na);
    }
    void dfs1(int u) {
        vis[u] = true;
        for(int v: g[u]) if(!vis[v]) dfs1(v);
        stk.push_back(u);
    }
    void dfs2(int u) {
        vis[u] = false;
        sccs[m].push_back(u);
        sccMap[u] = m;
        for(int v: rg[u]) if(vis[v]) dfs2(v);
    }
    void makeSccs() {
        int num = (n+1)<<1;
        for(int i=2;i<num;++i) if(!vis[i]) dfs1(i);
        for(auto i=stk.rbegin(),e=stk.rend();i!=e;++i) if(vis[*i]) {
            sccs.push_back(vector<int>());
            dfs2(*i);
            ++m;
        }
    }
    bool check() {
        for(int i=1;i<=n;++i) {
            if(sccMap[vtx(i)] == sccMap[vtx(-i)]) return false;
        }
        return true;
    }
    vector<bool> solve() {
        makeSccs();
        if(!check()) return vector<bool>();
        vector<bool> ret(n+1);
        vector<bool> rret(n+1);
        for(int i=0, l;i<m;++i) {
            l = lit(sccs[i].front());
            if(l>0 && ret[l] || l<0 && rret[-l]) continue;
            for(int x: sccs[i]) {
                x = lit(x);
                if(x>0) rret[x] = true;
                else ret[-x] = true;
            }
        }
        return ret;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    SAT2 sat(m);
    while(n--) {
        int a, b; cin >> a >> b;
        sat.addClause(a, b);
    }
    vector<bool> ans = sat.solve();
    if(ans.empty()) cout << 0;
    else {
        cout << 1 << '\n';
        for(int i=1;i<=m;++i) cout << ans[i] << ' ';
    }

    return 0;
}