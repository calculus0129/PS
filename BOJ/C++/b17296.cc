#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    double a=0;
    int ans = 0;
    while(a == 0.0 && n--) {
        cin >> a;
    }
    ans += ceil(a);
    while(n-- > 0) {
        cin >> a;
        ans += floor(a);
    }
    cout << ans;

    return 0;
}