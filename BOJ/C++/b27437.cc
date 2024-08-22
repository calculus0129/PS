#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sf(ll n) {
    return n*(n+1LL)>>1;
}

int srch(ll sum) {
    int lo=0, hi=2000000000, mid;
    while(lo+1<hi) {
        mid = (lo&hi) + ((lo^hi)>>1);
        if(sum<=sf(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    int x = srch(n);
    ll wee = sf(x-1);
    ll numer = n - wee;
    ll denom = x+1LL-numer;
    if(x&1) swap(numer, denom);

    cout << numer << '/' << denom;

    return 0;
}