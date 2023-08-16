#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
typedef long long int lli;
lli segtree[SIZE<<1];

void init() {
    for(int i=16, j, e;i>=0;--i) {
        for(j=1<<i,e=j<<1;j<e;++j) {
            segtree[j] = segtree[j<<1] + segtree[j<<1|1];
        }
    }
}

lli sum(int x, int y, int start=0, int end=SIZE-1, int node=1) {
    if(x <= start && end <= y) {
        return segtree[node];
    }
    if(start > y || end < x) return 0LL;
    int mid = start + end >> 1;
    return sum(x, y, start, mid, node<<1) + sum(x, y, mid+1, end, node<<1|1);
}

void change(int a, lli b) {
    a += SIZE;
    lli dif = b - segtree[a];
    if(dif) {
        do segtree[a] += dif;
        while (a >>= 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    for(int i=0;i<n;++i) cin >> segtree[SIZE+i];
    init();
    while(q--) {
        int a, b, x, y;
        cin >> x >> y >> a >> b;
        if(y<x) swap(x, y);
        cout << sum(x-1, y-1) << '\n';
        change(a-1, b);
    }
    return 0;
}