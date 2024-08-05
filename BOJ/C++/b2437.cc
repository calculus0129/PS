#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i=0;i<n;++i) cin >> arr[i];
	sort(arr, arr+n);
	int tgt = 1, idx=0;
	while(idx<n && arr[idx]<=tgt) {
		tgt += arr[idx++];
	}
	cout << tgt;
	return 0;
}
