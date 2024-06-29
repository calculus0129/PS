#include <bits/stdc++.h>
using namespace std;
int m, ans, s[1010];
bool isMale[1010];
typedef pair<int, int> pii;
// unordered_map<int, unordered_set<pii>> graph;
struct edge {
    int a, b, w;
    bool operator<(const edge & other) const {
        return w>other.w; // the opposite side for pq implementation
    }
};

priority_queue<edge> edges;

int find(int a) {
    if(s[a] == a) return a;
    return s[a] = find(s[a]);
}

bool eq(int a, int b) {
    int sa = find(a), sb = find(b);
    return sa == sb;
}

void uni(int a, int b) {
    int sa = find(a), sb = find(b);
    if(sa == sb) return;
    s[sb] = sa;
}

void addEdge(int a, int b, int c) {
    edges.push({a, b, c});
}

void kruskal() {
    vector<edge> mst;
    while(!edges.empty() && mst.size()<m-1) {
        edge e = edges.top(); edges.pop();
        if(eq(e.a, e.b)) continue;
        mst.push_back(e);
        uni(e.a, e.b);
        ans += e.w;
    }
    if(mst.size() < m-1) ans = -1;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> m >> n;
    char c;
    for(int i=1;i<=m;++i) {
        s[i] = i;
        cin >> c;
        isMale[i] = (c == 'M');
    }
    while(n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(isMale[a] != isMale[b]) addEdge(a, b, c);
    }

    kruskal();

    cout << ans;

    return 0;
}