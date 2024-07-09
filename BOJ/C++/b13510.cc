#include <bits/stdc++.h>
using namespace std;
const int SZ = 1<<17;

struct Seg {
    int T[SZ<<1];
    void update(int x, int val) {
        x |= SZ; T[x] = val;
        while(x>>=1) {
            T[x] = max(T[x<<1], T[x<<1|1]);
        }
    }

    int query(int l, int r) {
        if(l>r) return 0;
        l |= SZ; r |= SZ;
        int ret = 0;
        while(l<=r) {
            if(l&1) ret = max(ret, T[l++]);
            if(~r&1) ret = max(ret, T[r--]);
            l>>=1, r>>=1;
        }
        return ret;
    }
} seg;

int n;
int sz[SZ], dep[SZ], par[SZ], top[SZ], in[SZ], out[SZ];
bool chk[SZ];
vector<int> tree[SZ];
vector<pair<int,int>> graph[SZ], init_updates;

// sz, dep, par + graph -> tree && edge - weight mapping.
void dfs1(int u = 1) {
    chk[u] = true;
    sz[u] = 1;
    for(auto [v, w]: graph[u]) if(!chk[v]) {
        tree[u].push_back(v);
        init_updates.push_back({v, w});
        dep[v] = dep[u] + 1; par[v] = u;
        dfs1(v); sz[u] += sz[v];
        if(sz[v] > sz[tree[u][0]]) swap(tree[u].back(), tree[u][0]); // 이게 된다니...ㄷㄷ
    }
}

int pv;
void dfs2(int u = 1) {
    in[u] = ++pv;
    for(int v: tree[u]) {
        top[v] = v == tree[u][0] ? top[u] : v;
        dfs2(v);
    }
    out[u] = pv;
}

void init() {
    dfs1();
    dfs2();
    for(auto [v, w]: init_updates) {
        seg.update(in[v], w);
    }
}

int query(int a, int b) {
    int ret = 0;
    while(top[a]^top[b]) {
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int head = top[a];
        ret = max(ret, seg.query(in[head], in[a]));
        a = par[head];
    }
    if(dep[a]>dep[b]) swap(a, b);
    if(a!=b) ret = max(ret, seg.query(in[a]+1, in[b])); // 이거 +1도 그렇고 if문도 잘 붙여야 한다! 이거때문에 몇번은 틀렸다...!!!
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<int,int>> edge;
    edge.reserve(SZ);
    for(int i=0, a, b, c;i<n-1;++i) {
        cin >> a >> b >> c;
        edge.push_back({a, b});
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    init();
    int q, a, b, c;
    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        if(a == 1) {
            int u = edge[b-1].first;
            int v = edge[b-1].second;
            int ch = (dep[u] > dep[v]) ? u : v; // Choose the deeper node as the child
            seg.update(in[ch], c);
        } else {
            cout << (b==c?0:query(b, c)) << '\n';
        }
    }

    return 0;
}