#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int x, y, r; cin >> x >> y;
    int w, s; cin >> w >> s;
    long long int ans = 0LL;
    if(w*2<=s) ans = (LLI)(x+y)*w;
    else {
        ans += (LLI)min(x, y) * s;
        r = max(x, y)-min(x, y);
        if(w<=s) {
            ans += (LLI)r*w;
        } else {
            if(r&1) {
                ans += w;
                r^=1;
            }
            ans += (LLI)r * s;
        }
    }
    cout << ans;

    return 0;
}