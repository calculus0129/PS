#include <bits/stdc++.h>
using namespace std;
int t[15],p[15],dp[16];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        cin >> t[i] >> p[i];
    }
    
    for(int day=1,j;day<=n;++day) {
        dp[day] = dp[day-1];
        for(j=0;j<n;++j) if(j+t[j] == day) {
            dp[day] = max(dp[day], dp[j]+p[j]);
        }
    }
    cout << dp[n];

    return 0;
}