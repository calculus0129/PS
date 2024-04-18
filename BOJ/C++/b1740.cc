#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll n, ans=0LL, m=1LL;
    cin >> n;
    while(n) {
        if(n&1LL) {
            ans += m;
        }
        n>>=1;
        m*=3LL;
    }
    cout << ans;
    return 0;
}