#include <bits/stdc++.h>
using namespace std;
int f[20][200100];
int query(int n, int x) {
	for(int i=0;n;n>>=1,++i) if(n&1) x = f[i][x];
	return x;
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int m, n, q, x;
	cin >> m;
	for(int i=1;i<=m;++i) cin >> f[0][i];
	for(int i=1,j;i<19;++i) {
		for(j=1;j<=m;++j) f[i][j] = f[i-1][f[i-1][j]];
	}
	cin >> q;
	while(q--) {
		cin >> n >> x;
		cout << query(n, x) << '\n';
	}

	return 0;
}
