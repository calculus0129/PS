#include <bits/stdc++.h>
using namespace std;
const int SIZE=1<<17;
int segtree[SIZE<<1];

int normalize(int x) {
    return x<0?-1:x>0?1:0;
}

void init() {
    for(int i=16,j,e;i>=0;--i) {
        for(j=0,e=1<<i;j<e;++j) {
            segtree[e|j] = segtree[(e|j)<<1]*segtree[(e|j)<<1|1];
        }
    }
}

void update(int pos, int v) {
    int m = SIZE+pos;
    segtree[m]=normalize(v);
    while(m>>=1) {
        segtree[m] = segtree[m<<1]*segtree[m<<1|1];
    }
}

int mul(int left, int right, int start=0, int end=SIZE-1, int node=1) {
    if(right<start || end<left) return 1;
    if(left<=start && end<=right) return segtree[node];

    int mid = start+end>>1;
    // int ret = 1;
    // while()

    return mul(left, right, start, mid, node<<1)*
        mul(left, right, mid+1, end, node<<1|1);
}

char sgn(int i) {
    if(i<0) return '-';
    if(i>0) return '+';
    return '0';
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, k, a, b;
    char c;
    while(cin >> n >> k) {
        fill(segtree+SIZE, segtree+SIZE*2, 1);
        for(int i=0;i<n;++i) {
            cin >> a;
            segtree[SIZE|i] = normalize(a);
        }
        init();
        while(k--) {
            cin >> c >> a >> b;
            switch(c) {
                case 'C':
                update(a-1, b);
                break;
                default:
                cout << sgn(mul(a-1, b-1));
            }
        }
        cout << '\n';
    }


    return 0;
}