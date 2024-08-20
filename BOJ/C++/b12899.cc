#include <bits/stdc++.h>
using namespace std;
const int SZ = 1<<21;
int seg[SZ<<1];

void q1(int x, int v=1) {
    x += SZ;
    while(x) {
        seg[x] += v;
        x>>=1;
    }
}
int sum(int l, int r, int s=0, int e=SZ-1) {
    l += SZ, r += SZ;
    int ret=0;
    while(l<=r) {
        if(l&1) ret += seg[l++];
        if(~r&1) ret += seg[r--];
        l>>=1, r>>=1;
    }
    return ret;
}
int q2(int x) {
    int lo=0, hi=SZ-1, mid;
    auto check = [x](int q) -> bool {
        return sum(0, q) >= x;
    };
    if(check(lo)) hi = lo;
    else while(lo+1<hi) {
        mid = lo + hi >> 1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    q1(hi, -1);
    return hi;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int a, x;
        cin >> a >> x;
        if(a == 1) q1(x);
        else cout << q2(x) << '\n';
    }

    return 0;
}