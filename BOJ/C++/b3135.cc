#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, ans; cin >> a >> b;
    ans = abs(a-b);
    int n, k; cin >> n;
    while(n--) {
        cin >> k; ans = min(ans, abs(k-b)+1);
    }
    cout << ans;
    return 0;
}