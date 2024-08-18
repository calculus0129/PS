#include <bits/stdc++.h>
using namespace std;

struct SAT2 {
    const int n;
    int m;
    vector<vector<int>> g, rg;
    vector<int> stk, sccMap;
    vector<bool> visited;
    SAT2(int n)
    : n(n), m(0) {
        int num = (n+1)<<1;
        g.resize(num);
        rg.resize(num);
        sccMap.resize(num);
        visited.resize(num);
    }
    int vtx(int literal) {
        return abs(literal)<<1|(literal<0);
    }
    int lit(int vertex) {
        return (vertex>>1)*((vertex&1)?-1:1);
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
        visited[u] = true;
        for(int v: g[u]) if(!visited[v]) dfs1(v);
        stk.push_back(u);
    }
    void dfs2(int u, int num) {
        visited[u] = false;
        sccMap[u] = num;
        for(int v: rg[u]) if(visited[v]) dfs2(v, num);
    }
    void makeScc() {
        int num = 2*(n+1), len = 0;
        for(int i=2;i<num;++i) if(!visited[i]) dfs1(i);
        for(auto i=stk.rbegin(),e=stk.rend();i!=e;++i) {
            if(visited[*i]) dfs2(*i, len++);
        }
        m = len;
    }
    bool check() {
        for(int i=1, x, nx;i<=n;++i) {
            x = vtx(i), nx = vtx(-i);
            if(sccMap[x] == sccMap[nx]) return false;
        }
        return true;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    SAT2 sat2(m);
    while(n--) {
        int a, b; cin >> a >> b;
        sat2.addClause(a, b);
    }
    sat2.makeScc();
    cout << sat2.check();
    return 0;
}