#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b, int c) {
    return lcm(lcm(a, b), c);
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int ans = lcm(a, b, c);
    ans = min(ans, lcm(a, b, d));
    ans = min(ans, lcm(a, b, e));
    ans = min(ans, lcm(a, c, d));
    ans = min(ans, lcm(a, c, e));
    ans = min(ans, lcm(a, d, e));
    ans = min(ans, lcm(b, c, d));
    ans = min(ans, lcm(b, c, e));
    ans = min(ans, lcm(b, d, e));
    ans = min(ans, lcm(c, d, e));
    cout << ans;
    return 0;
}