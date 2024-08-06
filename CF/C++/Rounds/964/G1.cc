#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int inp; cin >> inp;
    return inp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int lo, hi, mid, T; cin >> T;
    while(T--) {
        lo=1, hi=999;
        while(lo+1<hi) {
            mid = lo+hi>>1;
            if(mid*mid != query(mid, mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        cout << "! " << hi << endl;
    }

    return 0;
}