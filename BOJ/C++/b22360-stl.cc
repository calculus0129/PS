#include <bits/stdc++.h>
#define X first
#define Y second
#define ADD(x,y) make_pair((x).X+(y).X, (x).Y+(y).Y)
#define NEG(x) make_pair(-(x).X, -(x).Y)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int SZ = 200008;

vector<int> g[SZ], gg[SZ];
char str[SZ];
int sz[SZ], par[SZ];
int n;
ll ans;
unordered_map<char, pii> mapper; // (U-C, P-C). -->(0,0)

void dfs(int u = 1) {
    g[u].reserve(gg[u].size());
    for(int v: gg[u]) if(v!=par[u]) {
        g[u].push_back(v);
        par[v] = u;
        dfs(v);
    }
}

void dfs1(int u = 1) {
    sz[u] = 1;
    for(int &v: g[u]) {
        dfs1(v); sz[u] += sz[v];
        if(sz[v]>sz[g[u][0]]) swap(v, g[u][0]);
    }
}

void append(const map<pii, int> &src, map<pii, int> &dst) {
    for(auto [pa, num]: src) dst[pa] += num;
}


void concat_indexify(int idx, const map<pii, int> &src, map<pii, map<int,int>> &dst) {
    for(const auto &[p, i]: src) dst[p].insert({idx, i});
}

void solve(const map<pii, map<int,int>> &data, const map<pii, int> &ret, int u) {
    pii up = NEG(mapper[str[u-1]]);
    // cout << "solve() called with u = " << u << " and up = (" << up.X << ", " << up.Y << ")\n";
    // cout << "Current ret map:\n";
    // for (const auto &[k, v] : ret) {
    //     cout << "  ((" << k.X << ", " << k.Y << ") -> " << v << ")\n";
    // }
    // First, u->subtree
    if(ret.find(up) != ret.end()) ans += ret.at(up);
    // Second, subtree->u->another subtree
    ll add=0LL;
    for(const auto &[p0, p0mp]: data) {
        pii neg = ADD(NEG(p0), up);
        if(ret.find(neg) == ret.end()) continue;
        int tot = ret.at(neg);
        for(auto [idx, ni]: p0mp) {
            add += ni*((ll)tot-(data.find(neg)==data.end() || data.at(neg).find(idx) == data.at(neg).end() ? 0 : data.at(neg).at(idx)));
        }
    }
    ans += add>>1;
}

map<pii, int> concat(int p, const map<pii, int> &src) {
    map<pii, int> ret;
    ret[mapper[str[p-1]]]=1;
    for(auto [pa, num]: src) ret[ADD(pa, mapper[str[p-1]])] += num;
    return ret;
}

map<pii, int> work(int u = 1) {
    map<pii, map<int,int>> data;
    map<pii, int> ret, tmp;
    // if(g[u].empty()) return ret({mapper[str[u-1]], 1});
    for(int i=0,e=g[u].size();i<e;++i) {
        tmp = work(g[u][i]);
        append(tmp, ret);
        concat_indexify(i, tmp, data);
    }
    solve(data, ret, u);

    return concat(u, ret);
}

// int getcentroid(int cap, int u) {
//     for(int v: g[u]) if(v!=par[u] && sz[v]*2>=cap) return getcentroid(cap, v);
//     return u;
// }

// pii prefix;
// void work(int u, int idx) {

// }

// void dnq(int u = 1, int p = -1) {
//     if(sz[u]<4) return;
//     getsize(u, p);
//     int c = getcentroid(sz[u], u), idx=0;
//     mp.clear();
//     pii initprefix = {0,0};
//     switch(str[u-1]) {
//         case 'U':
//             initprefix.first++;
//         case 'C':
//             initprefix.first--;
//             initprefix.second--;
//         default:
//             initprefix.second++;
//     }
//     for(int v: g[u]) {
//         prefix = initprefix;
//         work(v, idx);
//         ++idx;
//     }
// }

void debug1(int u = 1) {
    cout << u << ": ";
    for(int v: g[u]) cout << v << ' ';
    cout << '\n';
    for(int v: g[u]) debug1(v);
}

int main() {
    mapper['U'] = {2,0};
    mapper['C'] = {-1,-1};
    mapper['P'] = {0,2};
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    for(int i=0, a, b;i<n-1;++i) {
        cin >> a >> b;
        gg[a].push_back(b);
        gg[b].push_back(a);
    }
    dfs();
    dfs1();
    // debug1();
    work();
    cout << ans;

    return 0;
}