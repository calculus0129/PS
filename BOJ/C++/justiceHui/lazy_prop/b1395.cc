#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int segtree[SIZE<<1], lazy[SIZE<<1];

void update_lazy(int start, int end, int node) {
    if(lazy[node]&1) {
        segtree[node] = end - start + 1 - segtree[node];
        if(start!=end) {
            lazy[node<<1]++;
            lazy[node<<1|1]++;
        }
    }
    lazy[node] = 0;
}

void update(int l, int r, int start=0, int end = SIZE-1, int node = 1) {
    if(l<=start && end <= r) {
        lazy[node]++;
        update_lazy(start, end, node);
        return;
    }
    update_lazy(start, end, node);
    if(r < start || end < l) return;
    int mid = start + end >> 1;
    update(l, r, start, mid, node<<1);
    update(l, r, mid+1, end, node<<1|1);
    segtree[node] = segtree[node<<1] + segtree[node<<1|1];
}

int sum(int l, int r, int start = 0, int end = SIZE - 1, int node = 1) {
    update_lazy(start, end, node);
    if(l<=start && end <= r) {
        return segtree[node];
    }
    if(r < start || end < l) return 0;
    int mid = start + end >> 1;
    return sum(l, r, start, mid, node<<1) + sum(l, r, mid+1, end, node<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    while(m--) {
        cin >> a >> b >> c;
        if(a) {
            cout << sum(b-1, c-1) << '\n';
        } else {
            update(b-1, c-1);
        }
    }
    


    return 0;
}