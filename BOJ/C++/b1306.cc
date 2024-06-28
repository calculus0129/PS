#include <bits/stdc++.h>
using namespace std;
int m, n;
const unsigned int SIZE=1<<20;

int segtree[SIZE<<1];
void init() {
    for(int i=19, j, e;i>=0;--i) {
        e=1<<i;
        for(j=0;j<e;++j) {
            segtree[e+j] = max(segtree[e+j<<1], segtree[e+j<<1|1]);
        }
    }
}

int mx(int left, int right, int start=0, int end=SIZE-1, int node=1) {
    if(right<start || left>end) return 0;
    if(left<=start && end<=right) return segtree[node];
    int mid=start+end>>1;
    return max(mx(left, right, start, mid, node<<1), mx(left, right, mid+1, end, node<<1|1));
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0;i<m;++i) {
        cin >> segtree[SIZE+i];
    }
    init();
    for(int i=n-1;i<=m-n;++i) {
        cout << mx(i-(n-1), i+(n-1)) << ' ';
    }

    return 0;
}