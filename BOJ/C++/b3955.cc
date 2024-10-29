#include <bits/stdc++.h>
using namespace std;

// Input: a and b. (Both must be nonnegative. && Both must not be 0.)
// Output: gcd, s, t
// |s| <= b/gcd, |t| <= a/gcd,
// as + bt = gcd(a,b)
tuple<int,int,int> EEA(int a, int b) {
    int r0 = a, r1 = b, r;
    int s0 = 1, s1 = 0, s;
    int t0 = 0, t1 = 1, t;
    int q;
    while(r1) {
        r = r0 % r1;
        q = r0 / r1;
        s = s0 - q * s1;
        t = t0 - q * t1;
        r0 = r1, r1 = r;
        s0 = s1, s1 = s;
        t0 = t1, t1 = t;
    }
    return make_tuple(r0, s0, t0);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, T, d, s, t; cin >> T;
    while(T--) {
        cin >> b >> a;
        tie(d, s, t) = EEA(a, b);
        if(d>1) cout << "IMPOSSIBLE\n";
        else {
            while(t>=0) {
                t -= a;
                s += b;
            }
            if(s>1'000'000'000) {
                cout << "IMPOSSIBLE\n";
            } else cout << s << '\n';
        }
    }
    return 0;
}