#include <bits/stdc++.h>
#define X first
#define Y second
#define ADD(x,y) make_pair((x).X+(y).X, (x).Y+(y).Y)
#define NEG(x) make_pair(-(x).X, -(x).Y)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int SZ = 200008;

bool wasCentroid[SZ], visited[SZ];
vector<int> g[SZ];
char str[SZ];
int sz[SZ], par[SZ];
int n;
ll ans;
unordered_map<char, pii> mapper; // (U-C, P-C). -->(0,0)

int getsize(int u = 1, int b = -1) {
    sz[u] = 1;
    for(int v: g[u]) if(v!=b) {
        par[v]=u;
        sz[u] += getsize(v, u);
    }
    return sz[u];
}

int getcentroid(int cap, int u) {
    for(int v: g[u]) if(v!=par[u] && sz[v]*2>=cap) return getcentroid(cap, v);
    return u;
}

// Custom hash function for pair<int, int>
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // Combine hashes
    }
};

unordered_map<pii, unordered_map<int,int>, hash_pair> dat;
unordered_map<pii, int, hash_pair> tot;

void solve(int u) { //const map<pii, map<int,int>> &dat, const map<pii, int> &ret, int u) {
    pii up = NEG(mapper[str[u-1]]);
    // cout << "solve() called with u = " << u << " and up = (" << up.X << ", " << up.Y << ")\n";
    // cout << "Current tot map:\n";
    // for (const auto &[k, v] : tot) {
    //     cout << "  ((" << k.X << ", " << k.Y << ") -> " << v << ")\n";
    // }
    // First, u->subtree
    if(tot.find(up) != tot.end()) ans += tot.at(up);
    // Second, subtree->u->another subtree
    ll add=0LL;
    for(const auto &[p0, p0mp]: dat) {
        pii neg = ADD(NEG(p0), up);
        if(tot.find(neg) == tot.end()) continue;
        int total = tot.at(neg);
        for(const auto &[idx, ni]: p0mp) {
            add += ni*((ll)total-(dat.find(neg)==dat.end() || dat.at(neg).find(idx) == dat.at(neg).end() ? 0 : dat.at(neg).at(idx)));
        }
    }
    ans += add>>1;
    dat.clear();
    tot.clear();
}


// void append(const map<pii, int> &src, map<pii, int> &dst) {
//     for(auto [pa, num]: src) dst[pa] += num;
// }

// void concat_indexify(int idx, const map<pii, int> &src, map<pii, map<int,int>> &dst) {
//     for(const auto &[p, i]: src) dst[p].insert({idx, i});
// }

// map<pii, int> concat(int p, const map<pii, int> &src) {
//     map<pii, int> ret;
//     ret[mapper[str[p-1]]]=1;
//     for(auto [pa, num]: src) ret[ADD(pa, mapper[str[p-1]])] += num;
//     return ret;
// }

// map<pii, int> work(int u = 1) {
//     map<pii, map<int,int>> dat;
//     map<pii, int> ret, tmp;
//     // if(g[u].empty()) return ret({mapper[str[u-1]], 1});
//     for(int i=0,e=g[u].size();i<e;++i) {
//         tmp = work(g[u][i]);
//         append(tmp, ret);
//         concat_indexify(i, tmp, dat);
//     }
//     solve(dat, ret, u);

//     return concat(u, ret);
// }

void conquer(int u, int idx, pii prefix={0,0}) {
    visited[u] = true;
    pii m = ADD(prefix, mapper[str[u-1]]);
    tot[m]++;
    dat[m][idx]++;
    for(int v: g[u]) if(!visited[v]) {
        conquer(v, idx, m);
    }
}

void dnq(int u = 1, int p = -1) {
    getsize(u, p);
    if(sz[u]<4) return;
    int c = getcentroid(sz[u], u), idx=0;
    visited[c] = true;
    for(int v: g[c]) if(!visited[v]) {
        conquer(v, idx);
        idx++;
    }

    solve(c);
    
    // divide
    wasCentroid[c] = true;
    memcpy(visited, wasCentroid, sizeof(visited));
    for(int v: g[c]) if(!wasCentroid[v]) dnq(v, c);
}

// void debug1(int u = 1) {
//     cout << u << ": ";
//     for(int v: g[u]) cout << v << ' ';
//     cout << '\n';
//     for(int v: g[u]) debug1(v);
// }

int main() {
    mapper['U'] = {2,0};
    mapper['C'] = {-1,-1};
    mapper['P'] = {0,2};
    dat.rehash(SZ); tot.rehash(SZ);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    for(int i=0, a, b;i<n-1;++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dnq();
    cout << ans;

    return 0;
}