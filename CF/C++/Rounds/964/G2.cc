#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int inp; cin >> inp;
    return inp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int lo, hi, m1, m2, T, q; cin >> T;
    while(T--) {
        lo=1, hi=999;
        while(lo+1<hi) {
            m1 = (lo*2+hi)/3;
            m2 = (lo+hi*2)/3;
            q = query(m1, m2);
            if(q == (m1+1)*(m2+1)) hi=m1;
            else if(q == m1*m2) lo=m2;
            else {
                lo=m1;
                hi=m2;
            }
        }
        cout << "! " << hi << endl;
    }

    return 0;
}