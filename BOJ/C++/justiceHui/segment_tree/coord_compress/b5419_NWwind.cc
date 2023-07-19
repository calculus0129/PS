#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
const int SIZE = 1<<17;
int segtree[SIZE<<1];

int sum(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    if(l <= start && end <= r) return segtree[node];
    if(r < start || l > end) return 0;
    int mid = start+end>>1;
    return sum(l, r, start, mid, node<<1) + sum(l, r, mid+1, end, node<<1|1);
}

void inc(int pos, int val) {
    int node = pos + SIZE;
    if(val) do segtree[node]+=val;
    while (node>>=1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, n, a, b, i, idx;
    cin >> t;
    typedef pair<int,int> pii;
    vector<pii> v;
    vector<int> vi;
    size_t ans;
    while(t--) {
        v.clear();
        vi.clear();
        memset(segtree, 0, sizeof(segtree));
        ans=0;
        cin >> n;
        i=n;
        while(i--) {
            cin >> a >> b;
            v.push_back({a, b});
            vi.push_back(b);
        }
        sort(ALL(vi));
        vi.erase(unique(ALL(vi)), vi.end());
        // x coord: greater first, y coord: less first
        sort(ALL(v), [&](pii const &a, pii const &b) {
            return (a.first==b.first)?a.second<b.second:a.first>b.first;
        });
        for(auto const &i: v) {
            idx = lower_bound(ALL(vi), i.second) - vi.begin();
            ans += sum(0, idx);
            inc(idx, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}