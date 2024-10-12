#include <bits/stdc++.h>
typedef long long ll;
const int BIG = 16769023;
using namespace std;

int ans(int n) {
    n = n+1>>1;
    ll ret=1LL, r=2LL;
    while(n) {
        if(n&1) ret = (ret*r)%BIG;
        r = (r*r)%BIG;
        n >>= 1;
    }

    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    cout << ans(n);

    return 0;
}