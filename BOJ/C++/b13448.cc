#include <bits/stdc++.h>
using namespace std;
const int SZ = 100008;
typedef long long ll;
int n, t, dp[51][SZ];
struct Problem {
    int m, p, r;
} probs[51];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for(int i=1;i<=n;++i) cin >> probs[i].m;
    for(int i=1;i<=n;++i) cin >> probs[i].p;
    for(int i=1;i<=n;++i) cin >> probs[i].r;
    sort(probs+1, probs+n+1, [](Problem const &a, const Problem &b) -> bool {
        return (ll)a.p*b.r>(ll)a.r*b.p;
    });
    for(int i=1,j;i<=n;++i) {
        memcpy(dp[i], dp[i-1], sizeof(dp[0]));
        for(j=probs[i].r;j<=t;++j) dp[i][j] = max(max(dp[i][j], dp[i][j-1]), probs[i].m-(ll)j*probs[i].p<0LL?0:dp[i-1][j-probs[i].r]+probs[i].m-j*probs[i].p);
    }
    cout << dp[n][t];
    
    return 0;
}