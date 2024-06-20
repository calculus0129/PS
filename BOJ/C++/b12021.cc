#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll a, b, ans;
    cin >> a >> b;
    cout.precision(7);
    ans = sqrt(a*b);
    cout << ans << ' ' << ans;

    return 0;
}