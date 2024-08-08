#include <bits/stdc++.h>
#define BIG 2000000
using namespace std;
int n, w;
struct V2T {
	int x, y;
};

int d_L1(V2T a, V2T b) {
	return abs(a.x-b.x) + abs(a.y - b.y);
}

V2T arr[1010];
int dist[1010][1010], idx[1010][1010], dp[1010][1010];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> w;
	arr[0] = {1, 1};
	arr[1] = {n, n};
	dist[0][1] = n-1<<1;
	for(int i=2, j;i<=w+1;++i) {
		cin >> arr[i].x >> arr[i].y;
		for(j=0;j<i;++j) dist[j][i] = d_L1(arr[j], arr[i]);
	}
	dp[1][0] = BIG;
	for(int k=2, i, i1=0, i2=0;k<=w+1;++k) {
		dp[k-1][k] = dp[k][k-1] = BIG;
		for(i=0;i<k-1;++i) {
			dp[i][k] = dp[i][k-1] + dist[k-1][k];
			dp[k][i] = dp[k-1][i] + dist[k-1][k];
			idx[k][i] = idx[i][k] = k-1;
			if(dp[k-1][k] > dp[k-1][i] + dist[i][k]) {
				dp[k-1][k] = dp[k-1][i] + dist[i][k];
				i1 = i;
			}
			if(dp[k][k-1] > dp[i][k-1] + dist[i][k]) {
				dp[k][k-1] = dp[i][k-1] + dist[i][k];
				i2 = i;
			}
		}
		idx[k-1][k] = i1;
		idx[k][k-1] = i2;
	}
	int ax = 0, ay = w+1, ad = dp[0][w+1];
	for(int i=1;i<=w;++i) {
		if(ad > dp[i][w+1]) {
			ax = i;
			ay = w+1;
			ad = dp[i][w+1];
		}
		if(ad > dp[w+1][i]) {
			ax = w+1;
			ay = i;
			ad = dp[w+1][i];
		}
	}
	cout << ad << '\n';
	vector<bool> rev;
	while(!(ax == 0 && ay == 1)) {
		rev.push_back(ax<ay);
		if(ax<ay) ay = idx[ax][ay];
		else ax = idx[ax][ay];
	}
	for(int i=rev.size()-1;~i;--i) {
		cout << 1+rev[i] << '\n';
	}

	return 0;
}
