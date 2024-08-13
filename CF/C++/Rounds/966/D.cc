#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    int n, l, r, i, j;
    while(T--) {
        cin >> n;
        vector<int> arr(n);
        vector<ll> sum(n+1);
        for(i=0;i<n;++i) cin >> arr[i];
        for(i=0;i<n;++i) sum[i+1] = sum[i] + arr[i];
        string s; cin >> s;
        ll ans = 0LL;
        i = 0, j = n-1;
        while(i<j && i<n && j>=0) {
            while(i<j && i<n && s[i] == 'R') ++i;
            while(i<j && j>=0 && s[j] == 'L') --j;
            if(i<j && i<n && j>=0 && s[i] == 'L' && s[j] == 'R') {
                ans += sum[j+1]-sum[i];
                --j; ++i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}