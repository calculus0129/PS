#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define INF 201000
// x: dist, y: nodenum
struct p {
    int x, y;
};

using namespace std;
vector<p> g[20001];

bool cmp(const p &p1, const p &p2) {
    return p1.x<p2.x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    priority_queue<p, vector<p>, bool(*)(const p &, const p &)> pq(cmp);
    int m, n, k, a, b, w, d[20100], dist, x, y, nxtcost;
    cin >> m >> n >> k;
    pq.push({0,k});
    fill(d+1, d+m+1, INF); d[k]=0;
    while(n--) {
        cin >> a >> b >> w;
        g[a].push_back({-w, b});
    }
    p tmp;
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        b = tmp.y, dist = -tmp.x;
        if(d[b] != dist) continue;
        for(const p &t: g[b]) {
            x=-t.x, y=t.y;
            nxtcost = x + dist;
            if(d[y]>nxtcost) {
                d[y]=nxtcost;
                pq.push({-nxtcost, y});
            }
        }
    }
    for(int i=1;i<=m;++i) {
        if(d[i]==INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}