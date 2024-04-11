#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int arr[250001];
ll dp[250001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans;
    while(n!=0) {
        for(int i=0;i<n;++i) cin >> arr[i];
        ans = dp[0] = arr[0];
        for(int i=1;i<n;++i) {
            dp[i] = max(0LL, dp[i-1])+arr[i];
            if(dp[i]>ans) ans = dp[i];
        }
        cout << ans << '\n';
        cin >> n;
    }
    return 0;
}