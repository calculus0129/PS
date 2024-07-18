#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int n; ll x;
    while(t--) {
        cin >> n >> x;
        vector<ll> arr(n+1);
        vector<int> idx(n+1);
        for(int i=1;i<=n;++i) {
            cin >> arr[i];
            arr[i] += arr[i-1];
        }
        for(int i=1;i<=n;++i) {
            idx[i] = upper_bound(arr.begin()+i, arr.end(), x+arr[i-1]) - arr.begin();
            // cout << idx[i];
        }
        ll zeros = 0LL;
        vector<ll> dp(n+2);
        for(int i=n,j;i>=1;--i) if(idx[i]<=n) {
            j = idx[i];
            dp[i] = 1LL + dp[j + (i==j)];
            zeros += dp[i];
        }
        cout << n*((ll)n+1)/2LL-zeros << '\n';
    }
    return 0;
}