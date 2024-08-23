// Reference: calculus0129.github.io/ps/PS_template/

// For Additional Codes
// https://www.acmicpc.net/blog/view/106
// https://www.acmicpc.net/blog/view/114
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define X first
#define Y second
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

// class Edge: public tuple<int,int,int> {
//     public:

//     Edge(int u, int v, int w) : tuple<int,int,int>(u,v,w) {}

//     bool operator<(const Edge &e) const {
//         return get<2>(*this) < get<2>(e);
//     }
// };

int m,n;
vector<pair<int,int>> edges;

int s[1010];

void init() {
    for(int i=1;i<1010;++i) s[i] = i;
}
int Find(int a) {
    if(s[a] == a) return a;
    return s[a] = Find(s[a]);
}
bool merge(int a, int b) {
    a = Find(a), b = Find(b);
    if(a == b) return true;
    s[a] = s[b] = min(a, b);
    return false;
}

int ans;

int Kruskal(int num=0) {
    vector<int> ret;
    int cnt=0;
    init();
    ans = 0;
    // cout << "Kruskal begin with num=" << num << '\n';
    for(int i=num+1;i<=m && cnt<n-1;++i) if(!merge(edges[i].X, edges[i].Y)) {
        ans += i;
        ++cnt;
        ret.push_back(i);
        // cout << "i: " << i << " added\t";
        // cout << "cnt: " << cnt;
        // cout << '\n';
    }
    // cout << "n-1:" << n-1 << '\n';
    if(cnt<n-1) {
        ans = 0;
    }
    return ret.front();
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false); // Speed up IO
    int k, turn=1;
    cin >> n >> m >> k;
    edges.resize(m+1);

    for(int i=1;i<=m;++i) {
        cin >> edges[i].X >> edges[i].Y;
    }

    int mst = Kruskal();
    cout << ans << ' ';
    for(;turn<k && ans;++turn) {
        mst = Kruskal(mst);
        cout << ans << ' ';
    }
    for(;turn<k;++turn) cout << "0 ";

    return 0;
}
