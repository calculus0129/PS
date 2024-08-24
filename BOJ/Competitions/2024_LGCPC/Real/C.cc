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

#define BEGIN(x) (x).begin()
#define END(x) (x).end()
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

// https://cp-algorithms.com/graph/dinic.html
// for E: 1000000, V: 1200
struct Dinic {
    struct Edge {
        int from, to, cap, flow;
    };
    vector<Edge> edges;
    vector<vector<int>> adj;
    const int src=0, sink = 2801;
    int m = 0;
    vector<int> lvl, ptr;
    queue<int> q;

    Dinic() {
        adj.resize(2802);
        lvl.resize(2802);
        ptr.resize(2802);
    }

    void addEdge(int a, int b) {
        edges.push_back({a, b, 1, 0});
        edges.push_back({b, a, 0, 0});
        adj[a].push_back(m++);
        adj[b].push_back(m++);
    }
    bool bfs() {
        fill(ALL(lvl), -1);
        lvl[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int a = q.front(); q.pop();
            for(int i: adj[a]) if(!~lvl[edges[i].to] && edges[i].cap - edges[i].flow > 0) {
                lvl[edges[i].to] = lvl[a] + 1;
                q.push(edges[i].to);
            }
        }
        return ~lvl[sink];
    }
    int dfs(int a, int z) {
        if(a == sink || !z) return z;
        for(int &ci = ptr[a],i,sz=adj[a].size();ci<sz;ci++) {
            Edge &e = edges[i=adj[a][ci]];
            if(lvl[e.to] == lvl[a] + 1 && e.cap - e.flow > 0) {
                if(int x = dfs(e.to, min(z, e.cap - e.flow))) {
                    e.flow += x;
                    edges[i^1].flow -= x;
                    return x;
                }
            }
        }
        return 0;
    }
    int maxFlow() {
        int f = 0;
        while(bfs()) {
            fill(ALL(ptr), 0);
            while(int x = dfs(src, 400)) f += x;
        }
        return f;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    Dinic dinic;
    int n, k; cin >> n >> k;
    for(int i=n+1;i<=k;++i) dinic.addEdge(dinic.src, i);
    for(int i=1;i<=n;++i) dinic.addEdge(800+i, dinic.sink);
    for(int i=1,j;i<=n;++i) for(j=1;j<=k;++j) {
        int a; cin >> a;
        if(a) dinic.addEdge(j, 800+i);
    }
    cout << dinic.maxFlow();

    return 0;
}
