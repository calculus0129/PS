#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int lcs_length(int arr[], int brr[], int n) {
    for(int i=1, j;i<=n;++i) {
        for(j=1;j<=n;++j) {
            dp[i][j] = ((arr[i] == brr[j])?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[n][n];
}

int main() {
    int n, arr[5001], rev_arr[5001];
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;
    for(int i=1, a;i<=n;++i) {
        cin >> a;
        arr[i] = rev_arr[n+1-i] = a;
    }
    cout << n - lcs_length(arr, rev_arr, n);

    return 0;
}