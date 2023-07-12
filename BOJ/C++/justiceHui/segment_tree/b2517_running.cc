#include <bits/stdc++.h>
using namespace std;
const size_t BIAS = 1<<19;
int segtree[BIAS<<1];

int sum(int l, int r, int start=0, int end=BIAS-1, int node=1) {
    if(l<=start && end<=r) return segtree[node];
    if(r<start || l>end) return 0;
    return sum(l, r, start, start+end>>1, node<<1) + sum(l, r, (start+end>>1)+1, end, node<<1|1);
}

void update(int idx, int v) {
    int node = idx+BIAS, dif = v-segtree[node];
    if(dif) do segtree[node]+=dif;
    while (node>>=1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    typedef pair<int,int> pii;
    int n, ans[BIAS];
    vector<pii> v;
    cin >> n;
    for(int i=0, a;i<n;++i) {
        cin >> a;
        v.push_back({i, a});
    }
    sort(v.begin(), v.end(), [&](pii const & a, pii const & b) {
        return (a.second==b.second)?a.first<b.first:a.second>b.second;
    });
    for(const auto &i: v) {
        update(i.first, 1);
        ans[i.first] = sum(0, i.first);
    }
    for(int i=0;i<n;++i) cout << ans[i] << '\n';

    return 0;
}