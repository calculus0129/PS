#include <bits/stdc++.h>
using namespace std;
const size_t SIZE = 1ULL<<20, BIG = 1000000007ULL;
size_t segtree[SIZE<<1], n;

void init() {
    for(int i=19, j, e;i>=0;--i) {
        for(e=1<<i, j=0;j<e;++j) {
            segtree[e+j] = segtree[e+j<<1] * segtree[e+j<<1|1] % BIG;
        }
    }
}
/*
size_t pow(size_t b, size_t exp) {
    size_t ret = 1ULL;
    do {
        if(exp&1) ret = ret * b % BIG;
        b = b * b % BIG;
    } while(exp>>=1);
    return ret;
}
*/
void change(size_t node, size_t c) {
    /*size_t m = pow(segtree[node], BIG-2ULL) * c % BIG;
    do segtree[node] = segtree[node] * m % BIG;
    while(node>>=1);*/
    segtree[node] = c;
    while(node>>=1) segtree[node] = segtree[node<<1] * segtree[node<<1|1ULL] % BIG;
}

size_t mul(size_t l, size_t r, size_t start=0, size_t end=SIZE-1ULL, size_t node = 1ULL) {
    if(l <= start && end <= r) return segtree[node];
    if(end < l || start > r) return 1ULL;
    size_t mid = start + end >> 1;
    return mul(l, r, start, mid, node<<1) * mul(l, r, mid+1, end, node<<1|1ULL) % BIG;
}

int main() {

    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, q, i;
    cin >> n >> a >> b;
    q = a + b;
    for(i=0;i<n;++i) cin >> segtree[SIZE + i];
    init();
    while(q--) {
        cin >> a >> b >> c;
        if(a==1) {
            change(b+SIZE-1, c);
        } else {
            cout << mul(b-1, c-1) << '\n';
        }
    }
    
    return 0;
}