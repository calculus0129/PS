#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<19;
int segtree[SIZE<<1], lazy[SIZE<<1];

void init() {
    for(int i=18, j, e;i>=0;--i) {
        for(j=1<<i,e=j<<1;j<e;++j) {
            segtree[j] = segtree[j<<1] xor segtree[j<<1|1];
        }
    }
}

void update_lazy(int start, int end, int node) {
    if(lazy[node] == 0) return;
    if(start!=end) {
        lazy[node<<1]^=lazy[node];
        lazy[node<<1|1]^=lazy[node];
    } else {
        segtree[node] ^= lazy[node];
    }
    lazy[node]=0;
}

void update(int l, int r, int k, int start=0, int end=SIZE-1, int node = 1) {
    if(l <= start && end <= r) {
        lazy[node] ^= k;
        update_lazy(start, end, node);
        return;
    }
    update_lazy(start, end, node);
    if(l > end || r < start) return;
    int mid = start + end >> 1;
    update(l, r, k, start, mid, node<<1);
    update(l, r, k, mid+1, end, node<<1|1);
    segtree[node] = segtree[node<<1] ^ segtree[node<<1|1];
}

int xo(int l, int r, int start=0, int end = SIZE - 1, int node = 1) {
    update_lazy(start, end, node);
    if(l <= start && end <= r) {
        return segtree[node];
    }
    if(l > end || r < start) return 0;
    int mid = start + end >> 1;
    return xo(l, r, start, mid, node<<1) xor xo(l, r, mid+1, end, node<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> segtree[SIZE|i];
    init();
    int m; cin >> m;
    int a, b, c, d;
    while(m--) {
        cin >> a >> b >> c;
        if(a==1) {
            cin >> d;
            update(b, c, d);
        } else {
            cout << xo(b, c) << '\n';
        }
    }

    return 0;
}