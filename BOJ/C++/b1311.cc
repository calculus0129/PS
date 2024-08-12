#include <bits/stdc++.h>
#define BIG 200000
using namespace std;
int dp[1<<20], cost[20][20];
int main() {
	int n;
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0,j;i<n;++i) for(j=0;j<n;++j) {
		cin >> cost[i][j];
	}		
	for(int i=1,j,num;i<(1<<n);++i) {
		dp[i] = BIG;
		num = 0;
		for(j=0;j<n;++j) if(i & (1<<j)) ++num;
		for(j=0;j<n;++j) dp[i] = min(dp[i&~(1<<j)] + cost[num-1][j], dp[i]);
	}	
	cout << dp[(1<<n)-1];
	return 0;
}
