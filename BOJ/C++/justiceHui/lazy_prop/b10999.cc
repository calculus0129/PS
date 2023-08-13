#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<20;
typedef long long int lli;
lli segtree[SIZE<<1], lazy[SIZE<<1];
int n;

void init() {
    for(int i=19, j, e;i>=0;--i) {
        for(j=1<<i,e=j<<1;j<e;++j) {
            segtree[j] = segtree[j<<1] + segtree[j<<1|1];
        }
    }
}

void update_lazy(int start, int end, int node) {
    if(lazy[node] != 0) {
        segtree[node] += (end - start + 1) * lazy[node];
        if(start != end) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_interval(int l, int r, lli dif, int start=0, int end=SIZE-1, int node=1) {
    if(l <= start && end <= r) {
        lazy[node] += dif;
        update_lazy(start, end, node);
        return;
    }
    update_lazy(start, end, node);
    if (start > r || end < l) return;
    int mid = start+end>>1;
    update_interval(l, r, dif, start, mid, node<<1);
    update_interval(l, r, dif, mid+1, end, node<<1|1);
    segtree[node] = segtree[node<<1] + segtree[node<<1|1];
}

lli sum(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    update_lazy(start, end, node);
    if(l <= start && end <= r) {
        return segtree[node];
    }
    if (start > r || end < l) return 0LL;
    int mid = start+end>>1;
    return sum(l, r, start, mid, node<<1) + sum(l, r, mid+1, end, node<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, k, a, b, c;
    lli d;
    cin >> n >> m >> k;
    for(int i=0;i<n;++i) cin >> segtree[SIZE + i];
    init();
    m+=k;
    while(m--) {
        cin >> a >> b >> c;
        if(a==1) {
            cin >> d;
            update_interval(b-1, c-1, d);
        } else {
            cout << sum(b-1, c-1) << '\n';
        }
    }


    return 0;
}