#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n, a, b, i, j, k, dp[101][101]={};
    cin >> m >> n;
    for(i=1;i<=m;++i) {
        fill(dp[i]+1, dp[i]+m+1, INF);
        dp[i][i]=0;
    }
    while(n--) {
        cin >> a >> b;
        dp[a][b]=0;
    }
    for(k=1;k<=m;++k) {
        for(i=1;i<=m;++i) for(j=1;j<=m;++j) {
            if(dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j] = dp[i][k]+dp[k][j];
        }
    }
    for(i=1;i<=m;++i) {
        k=0;
        for(j=1;j<=m;++j) if(dp[i][j] && dp[j][i]) ++k;
        cout << k << '\n';
    }
    
    return 0;
}