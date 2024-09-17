#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    map<int,ll> m;
    while(n--) {
        int x, t, c;
        cin >> x >> t >> c;
        m[x-t] += c;
    }
    ll ans = 0;
    for(auto [_, c]: m) {
        ans = max(ans, c);
    }
    cout << ans;
    return 0;
}