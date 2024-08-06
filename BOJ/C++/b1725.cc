#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n,a; cin >> n;
	vector<pii> stk;
	int ans = 0;
	for(int i=0;i<n;++i) 
	{
		cin >> a;
		int sec = i;
		while(!stk.empty() && stk.back().first>=a) {
			sec = stk.back().second;
			ans = max(ans, stk.back().first * (i-stk.back().second));
			stk.erase(prev(stk.end()));
		}
		stk.push_back({a, sec});
	}
	while(!stk.empty()) {
		ans = max(ans, stk.back().first * (n-stk.back().second));
		stk.erase(prev(stk.end()));
	}
	cout << ans;
	return 0;
}
