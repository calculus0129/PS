#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[100][2];

void init() {
    dp[1][1]=1LL;
    for(int i=2;i<=90;++i) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;
    cout << dp[n][0] + dp[n][1];
    return 0;
}