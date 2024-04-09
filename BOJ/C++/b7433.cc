#include <bits/stdc++.h>
#define EUCMOD(a, m) ((a)%(m)+(m))%m
using namespace std;
bool dp[10101][101];
int n, k, arr[10101];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0, a;i<n;++i) {
        cin >> a;
        arr[i] = EUCMOD(a, k);
    }
    dp[0][arr[0]] = true;
    for(int i=1, j;i<n;++i) {
        for(j=0;j<k;++j) {
            dp[i][j] = dp[i-1][EUCMOD(j-arr[i], k)] || dp[i-1][EUCMOD(j+arr[i], k)];
        }
    }

    cout << ((dp[n-1][0])?"Divisible":"Not divisible");

    return 0;
}