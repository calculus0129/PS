/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : calculus
 * Date : 2024-08-23
 * Source : calculus0129.github.io/ps/PS_template/
 * Description : My cpp PS template.
 */

// For Additional Codes
// https://www.acmicpc.net/blog/view/106
// https://www.acmicpc.net/blog/view/114
#include <bits/stdc++.h>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)

typedef long long ll;
#define X first
#define Y second

// #define P 1000000009
// #define SUM(x,y) (x+y)%P

using namespace std;

// Using the Policy-Based Data Structures
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Define the ordered set using Policy-Based Data Structures
template<typename T>
using om_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
int m_erase(om_set<T> &om, T val) {
    T idx = om.order_of_key(val);
    auto it = om.find_by_order(idx);
    if(*it == val) om.erase(it);
    return val;
}//*/

struct Institute {
    struct Edge {
        int from, to, lvl;
        Edge(int from, int to, int lvl) : from(from), to(to), lvl(lvl) {}
    };
    int n, m, hi;
    ll d;
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> val;
    vector<bool> vis;

    Institute(int n, ll d) : n(n), m(0), hi(600000), d(d) {
        adj.resize(n+1);
        val.resize(n+1);
        vis.resize(n+1);
    }

    void addEdge(int a, int b, int lvl) {
        edges.push_back(Edge(a, b, lvl));
        edges.push_back(Edge(b, a, lvl));
        adj[a].push_back(m);
        adj[b].push_back(m+1);
        m += 2;
    }

    ll insecurity(int a, int lvl) {
        ll ret = val[a];
        vis[a] = true;
        for(int i: adj[a]) if(!vis[edges[i].to] && edges[i].lvl <= lvl) ret += insecurity(edges[i].to, lvl);
        return ret;
    }

    ll danger(int lvl) {
        ll ret = 0LL;
        fill(ALL(vis), false);
        for(int i=1;i<=n;++i) if(!vis[i]) {
            ret = max(ret, insecurity(i, lvl));
        }
        return ret;
    }

    int minLevel() {
        auto check = [&](int lvl) -> bool{
            // cout << "check(" << lvl << "): " << danger(lvl) << "\td: " << d << '\n';
            return danger(lvl) >= d;
        };
        int lo = 0;
        if(check(lo)) return -1;
        if(!check(600000)) return -2;
        int mid;
        while(lo+1 < hi) {
            mid = lo+hi>>1;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        return hi;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; ll d;
    cin >> n >> m >> d;
    Institute inst(n, d);
    for(int i=1;i<=n;++i) cin >> inst.val[i];
    while(m--) {
        int a, b, lvl;
        cin >> a >> b >> lvl;
        inst.addEdge(a, b, lvl);
    }
    int q; cin >> q;
    while(q--) {
        cin >> m;
        switch(m) {
            int a, b, k, lvl;
            case 1:
                cin >> a >> b >> lvl;
                inst.addEdge(a, b, lvl);
                break;
            case 2:
                cin >> k >> a;
                inst.val[k] = a;
                break;
            case 3:
                cin >> d;
                inst.d = d;
                break;
            default:
                cout << inst.minLevel() << '\n';
        }
    }

    return 0;
}