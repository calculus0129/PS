#include <bits/stdc++.h>
#define SQR(x) (x)*(x)
using namespace std;

int dp[101010];

void work() {
    fill(dp, dp+101010, INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3, j,e;i<=100000;++i) {
        e = floor(sqrt(i));
        if(SQR(e) == i) dp[i] = 1;
        for(j=1;j<=e;++j) dp[i] = min(dp[i], 1+dp[i-j*j]);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    work();
    int n, ans =0;
    cin >> n;
    cout << dp[n];
    return 0;
}