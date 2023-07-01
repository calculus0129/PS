#include <bits/stdc++.h>
using namespace std;
struct connection {
    int a, b, w;
    bool operator<(const connection &e) const {
        return w<e.w;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n, i, a, b, w, D[1010], cnt=0, cost=0;
    cin >> m >> n;
    for(i=1;i<=m;++i) D[i]=i;
    vector<connection> v;
    while(n--) {
        cin >> a >> b >> w;
        v.push_back({a, b, w});
    }
    sort(v.begin(), v.end());
    auto idx = v.begin();
    while(cnt<m-1) {
        a = idx->a, b = idx->b, w=idx++->w;
        while(D[a]!=a) a = D[a];
        while(D[b]!=b) b = D[b];
        if(a == b) continue;
        ++cnt; cost+=w;
        D[a] = D[b] = min(a, b);
    }
    cout << cost;

    return 0;
}