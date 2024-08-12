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
	
	cout << dp[(1<<n)-1];
	return 0;
}
