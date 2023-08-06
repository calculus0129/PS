#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    //assert((.5<<1) == 1); // expression itself may not be supported.
    double x, y, D, T, l, t = 0;
    cin >> x >> y >> D >> T;
    l = sqrt(x*x+y*y);
    if(D<=T) t = l;
    else {
        double t1=0, t2=0;
        int m=0;
        if(l>=D*2) {
            m = floor(l/D) - 1;
            l -= D*m;
            t = T*m;
        }
        t1 = 2*T;
        if(l>=D) {
            t2 = T;
            l -= D;
        }
        t2 += min(T+(D-l), l);
        t += min(t1, t2);
    }
    cout.precision(10);
    cout << fixed;
    cout << t;
    return 0;
}