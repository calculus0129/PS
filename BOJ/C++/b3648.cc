#include <bits/stdc++.h>
using namespace std;
struct SAT2 {
    const int n;
    int m;
    vector<vector<int>> g, rg;
    vector<int> sccMap, stk;
    vector<bool> vis;
    SAT2(int n)
    : n{n}, m{0} {
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
        sccMap[u] = m;
        for(int v: rg[u]) if(vis[v]) dfs2(v);
    }
    void makeScc() {
        int num = (n+1)<<1;
        for(int i=4;i<num;++i) if(!vis[i]) dfs1(i);
        for(auto i=stk.rbegin(),e=stk.rend();i!=e;++i) if(vis[*i]) {
            dfs2(*i);
            ++m;
        }
    }
    bool check() {
        makeScc();
        for(int i=2;i<=n;++i) if(sccMap[vtx(i)] == sccMap[vtx(-i)]) return false;
        return true;
    }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, a, b;
    while(cin >> n) {
        SAT2 sat2(n);
        cin >> m;
        while(m--) {
            cin >> a >> b;
            if(abs(a) > abs(b)) swap(a, b);
            if(abs(a) == 1) {
                if(a == 1) continue;
                else a = b;
            }
            sat2.addClause(a, b);
        }
        cout << (sat2.check()?"yes":"no") << '\n';
    }
    return 0;
}