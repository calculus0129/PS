#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int segtree[SIZE<<1], arr[SIZE];

int smaller(int i1, int i2) {
    return arr[i1] == arr[i2] && i2<i1 || arr[i1]>arr[i2]?i2:i1;
}

void init() {
    for(int i=0;i<SIZE;++i) segtree[SIZE+i] = i;
    for(int i=16, j, e;i>=0;--i) {
        for(j=1<<i,e=j<<1;j<e;++j) {
            segtree[j] = smaller(segtree[j<<1], segtree[j<<1|1]);
        }
    }
}

void update(int idx, int val) {
    arr[idx] = val;
    int node = idx+SIZE;
    while(node>>=1) {
        segtree[node] = smaller(segtree[node<<1], segtree[node<<1|1]);
    }
}

int query(int start, int end, int left = 0, int right = SIZE-1, int node = 1) {
    if(right < start || end < left) return SIZE-1;
    if(start <= left && right <= end) return segtree[node];
    return smaller(query(start, end, left, left+right>>1, node<<1), query(start, end, (left+right>>1)+1, right, node<<1|1));
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    arr[SIZE-1] = INT_MAX;
    int n;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    init();
    int q, i, j, m; cin >> m;
    while(m--) {
        cin >> q >> i >> j;
        if(q==1) update(i-1, j);
        else cout << query(i-1, j-1)+1 << '\n';
    }
    
    return 0;
}