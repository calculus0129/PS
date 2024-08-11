#include <bits/stdc++.h>
using namespace std;
int arr[10][21];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int k, n; cin >> k >> n;
	for(int i=0, j, a;i<k;++i) for(j=0;j<n;++j) {
		cin >> a;
		arr[i][a] = j;
	}
	int cnt = 0;
	for(int i=1,j,gg;i<n;++i) for(j=i+1;j<=n;++j) {
		bool r = true, g = arr[0][i] < arr[0][j];
		for(gg=1;gg<k && r;++gg) {
			if(g != arr[gg][i] < arr[gg][j]) {
				r = false;
			}
		}
		if(r) cnt++;
	}
	cout << cnt;

	return 0;
}
