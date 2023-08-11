#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int sgt1[SIZE<<1], sgt2[SIZE<<1], arr[SIZE];

void init() {
    for(int i=16, j, e;i>=0;--i) {
        for(j=1<<i, e=j<<1;j<e;++j) {
            sgt1[j] = min(sgt1[j<<1], sgt1[j<<1|1]);
            sgt2[j] = max(sgt2[j<<1], sgt2[j<<1|1]);
        }
    }
}

int query1(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    if(l <= start && end <= r) return sgt1[node];
    if(start > r || end < l) return 1000000001;
    int mid = start+end>>1;
    return min(query1(l, r, start, mid, node<<1), query1(l, r, mid+1, end, node<<1|1));
}

int query2(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    if(l <= start && end <= r) return sgt2[node];
    if(start > r || end < l) return 0;
    int mid = start+end>>1;
    return max(query2(l, r, start, mid, node<<1), query2(l, r, mid+1, end, node<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i) cin >> arr[i];
    memcpy(sgt1+SIZE, arr, sizeof(int)*n);
    fill(sgt1+SIZE+n, sgt1+(SIZE<<1), 1000000001);
    memcpy(sgt2+SIZE, arr, sizeof(int) * n);
    init();
    int a, b;
    while(m--) {
        cin >> a >> b;
        --a; --b;
        cout << query1(a, b) << ' ' << query2(a, b) << '\n';
    }
    
    return 0;
}