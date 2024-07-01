#include <bits/stdc++.h>
#define BIG 1000000007LL
using namespace std;
typedef long long ll;
ll dp[51];

void fil() {
    dp[0]=dp[1]=1LL;
    for(int i=2;i<=50;++i) {
        dp[i] = (1+dp[i-1] + dp[i-2]) % BIG;
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    fil();
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}