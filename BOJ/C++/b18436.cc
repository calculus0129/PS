#include <bits/stdc++.h>
using namespace std;
const int SZ = 1<<17;

int seg[SZ<<1];

void update(int pos, int v) {
    int node = (pos|SZ);
    if(~(v ^ seg[node]) & 1) return;
    seg[node] ^= 1;
    node>>=1;
    while(node) {
        seg[node] = seg[node<<1] + seg[node<<1|1];
        node>>=1;
    }
}

int halls(int l, int r, int s=0, int e=SZ-1, int node=1) {
    if(r<s || e<l) return 0;
    if(l<=s && e<=r) return seg[node];
    int mid = s+e>>1;
    return halls(l, r, s, mid, node<<1) + halls(l, r, mid+1, e, node<<1|1);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0, a;i<n;++i) {
        cin >> a;
        if(a&1) {
            update(i, 1);
        }
    }
    int a, b, m, T; cin >> T;
    while(T--) {
        cin >> m >> a >> b;
        if(m == 1) {
            update(a-1, b);
        }
        else if(m == 2) {
            cout << b-a+1-halls(a-1,b-1) << '\n';
        }
        else {
            cout << halls(a-1, b-1) << '\n';
        }
    }
    return 0;
}