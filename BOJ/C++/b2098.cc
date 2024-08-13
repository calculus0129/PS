#include <bits/stdc++.h>
#define BIG 16000000
using namespace std;
int n, ec[16], cost[16][16], dp[1<<15][15];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int tmp;
    cin >> n >> tmp;
    --n;
    for(int i=0;i<n;++i) {
        cin >> dp[0][i];
        if(dp[0][i] == 0) dp[0][i] = BIG;
    }
    for(int i=0,j;i<n;++i) {
        cin >> ec[i];
        if(ec[i] == 0) ec[i] = BIG;
        for(j=0;j<n;++j) {
            cin >> cost[i][j];
            if(cost[i][j] == 0) cost[i][j] = BIG;
        }
    }
    for(int i=1,ie=1<<n,j,k;i<ie;++i) {
        for(j=0;j<n;++j) if(!(i&(1<<j))) {
            dp[i][j] = BIG;
            for(k=0;k<n;++k) if((i>>k)&1) {
                dp[i][j] = min(dp[i][j], dp[i&~(1<<k)][k]+cost[k][j]);
            }
        }
    }
    int ans = BIG;
    for(int j=0;j<n;++j) {
        ans = min(ans, dp[((1<<n)-1)&~(1<<j)][j] + ec[j]);
    }
    cout << ans;

    return 0;

}