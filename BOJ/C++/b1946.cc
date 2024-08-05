#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<pii> arr(n);
		for(int i=0;i<n;++i) cin >> arr[i].first >> arr[i].second;
		sort(arr.begin(), arr.end(), [](const pii &a, const pii &b) -> bool{
			return a.first < b.first;
		});
		int threshold=arr[0].second, ans = 1;
		for(int i=1;i<n;++i) if(arr[i].second < threshold) {
			++ans;
			threshold = arr[i].second;
		}
		cout << ans << '\n';
	}
	return 0;
}
