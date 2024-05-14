#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // I saw the role of x and y exchanged.
    int x, y; cin >> y >> x;
    double d = 100.0*x/y;
    int z = floor(d)+1;
    if(z>=100) cout << -1;
    else cout << (y*z-100*x)/(100-z) + ((y*z-100*x)%(100-z)==0?0:1);
    return 0;
}
// (x+a)/(y+a) >= z/100.
// a(100-z) >= yz-100x
// a >= yz-100x / 100-z