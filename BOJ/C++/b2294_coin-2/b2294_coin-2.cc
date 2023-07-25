#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int dp[10101], pdp[10101], visited[10101], v_visited[10101];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, cnt = 0;
    register int i, j, a;
    cin >> n >> k;
    for(i=1;i<=k;++i) dp[i]=-1;
    //dp[0] = 1;
    visited[0]=1;
    while(n--) {
        cin >> a;
        if(a<=k && !v_visited[a]) {
            v_visited[a]=1;
            for(i=a;i<=k;++i) if(visited[i-a]) {
                if(!visited[i] || dp[i]>dp[i-a]+1) {
                    visited[i]=1;
                    dp[i] = dp[i-a]+1;
                }
            }
        }
    }
    cout << dp[k];
    /*
    vector<int> arr;
    for(i=0;i<n;++i) {
        cin >> a;
        arr.push_back(a);
    }
    sort(ALL(arr));
    arr.erase(unique(ALL(arr)), arr.end());
    n = arr.size();
    if(arr.front()>k) cout << -1;
    else {
        while(!dp[k]) {
            memcpy(pdp, dp, sizeof(int)*(k+1));
            for(i=0;i<n;++i) {
                a = arr[i];
                for(j=a;j<=k;++j) dp[j] += pdp[j-a];
            }
            ++cnt;
        }
        cout << cnt;
    }*/
    return 0;
}