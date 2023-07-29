// https://code-angie.tistory.com/24
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    size_t n, l, i, s, t, ans;
    cin >> T;
    while(T--) {
        cin >> n >> s >> t;
        ans=0;
        while(n > 1) {
            if(n&1) ans += s;
            n>>=1;
            ans += min(n*s, t);
        }
        ans += s;
        cout << ans << '\n';
    }
    return 0;
}