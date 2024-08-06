#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[501][501];
int arr[501];
int sum[501];

void solve() {
	int n; cin >> n;
	memset(dp, 0, sizeof(dp)); // equivalent to sizeof(ll)*501*501
	memset(sum, 0, sizeof sum);
	for(int i=0;i<n;++i) cin >> arr[i];
	for(int i=0;i<n;++i) sum[i+1] = sum[i] + arr[i];
	for(int k=1,i,j;k<n;++k) {
		for(i=0;i<n-k;++i) 
		{
			ll mi = LLONG_MAX;
			for(j=0;j<k;++j) {
				mi = min(mi, dp[i][i+j]+dp[i+1+j][i+k]);
			}
			dp[i][i+k] = mi + sum[i+k+1] - sum[i];
		}
	}
	cout << dp[0][n-1] << '\n';	
}

int main() 
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
