#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    lli a, m=1LL, ans=0LL;
    cin >> a;
    while(a) {
        ans += m * (a%7LL);
        a/=7LL;
        m*=3LL;
    }
    cout << ans;
    return 0;
}