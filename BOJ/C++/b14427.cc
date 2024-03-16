#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int segtree[SIZE<<1];
int arr[SIZE]={INT_MAX,};
int n;

int arr_smaller_idx(int a, int b) {
    if(b<a) swap(a, b);
    return (arr[a]>arr[b])?b:a;
}

void init() {
    for(int i=1;i<=n;++i) segtree[SIZE +  i] = i;
    for(int i=16, j, e;i>=0;--i)
        for(j=1<<i,e=j<<1;j<e;++j) segtree[j] = arr_smaller_idx(segtree[j<<1], segtree[j<<1|1]);
}

void update(int idx, int num) {
    arr[idx] = num;
    idx += SIZE;
    while(idx>>=1)
        segtree[idx] = arr_smaller_idx(segtree[idx<<1], segtree[idx<<1|1]);
}

int min_idx(int l=0, int r=SIZE-1, int start = 0, int end = SIZE-1, int node = 1) {
    if(l<=start && r<=end) return segtree[node];
    if(l>end || r<start) return 0;
    return arr_smaller_idx(min_idx(l, r, start, start+end>>1, node<<1), min_idx(l, r, (start+end>>1)+1, end, node<<1|1));
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;++i) cin >> arr[i];
    init();

    int m, a, b, c;
    for(cin >> m;m>0;--m) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            update(b, c);
        }
        else if(a == 2) {
            cout << min_idx(0, SIZE-1) << '\n';
        }
    }

    return 0;
}