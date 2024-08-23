// Reference: calculus0129.github.io/ps/PS_template/

// For Additional Codes
// https://www.acmicpc.net/blog/view/106
// https://www.acmicpc.net/blog/view/114
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)

// #define P 1000000009
// #define SUM(x,y) (x+y)%P

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

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
}

struct Partitioning {
    const int n;
    vector<vector<int>> g;
    vector<bool> colors;
    vector<bool> visited;
    Partitioning(int n) : n(n) {
        g.resize(n+1);
        visited.resize(n+1);
        colors.resize(n+1);
    }
    void addEdge(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool dfs(int u, int from=0) {
        visited[u] = true;
        for(int v: g[u]) if(v!=from) {
            if(!visited[v]) {
                colors[v] = !colors[u];
                if(!dfs(v, u)) return false;
            } else if(colors[v] == colors[u]) return false;
        }
        return true;
    }
    bool solve() {
        for(int i=1;i<=n;++i) if(!visited[i] && !dfs(i)) return false;
        return true;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        Partitioning part(n);
        while(m--) {
            int a, b; cin >> a >> b;
            part.addEdge(a, b);
        }
        cout << (part.solve()?"YES\n":"NO\n");
    }
    return 0;
}
