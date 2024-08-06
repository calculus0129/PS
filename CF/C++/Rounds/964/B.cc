#include <bits/stdc++.h>
using namespace std;
int sgn(int x) {
    return x<0?-1:x>0?1:0;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int a1, a2, b1, b2, r;
    while(t--) {
        cin >> a1 >> a2 >> b1 >> b2;
        r = (sgn(a1-b1) + sgn(a2-b2) > 0) + (sgn(a2-b1) + sgn(a1-b2) > 0);
        cout << (r<<1) << '\n';
    }

    return 0;
}