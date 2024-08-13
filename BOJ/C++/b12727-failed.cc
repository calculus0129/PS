#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int work(int n) {
    ld m = 3+sqrt(5), ret = 1;
    while(n) {
        if(n&1) ret *= m;
        m*=m;
        n>>=1;
    }
    ret-=1000*(ret/(ld)1000);
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int i=1;i<=T;++i) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << work(n) << '\n';
    }
    return 0;
}