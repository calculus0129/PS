#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    bool dp[1010] = {false, true, false, true, };
    for(int i=4;i<=n;++i) {
        dp[i] = !(dp[i-1] && dp[i-3]);
    }
    cout << (dp[n]?"SK":"CY");
    return 0;
}