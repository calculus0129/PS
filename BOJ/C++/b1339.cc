#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp;
void work(string s) {
	int m=1;
	for(int i=s.size()-1;i>=0;--i) {
		mp[s[i]] += m;
		m*=10;
	}
}
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		work(s);
	}
	priority_queue<int> pq;
	for(auto p: mp) pq.push(p.second);
	int i=9, ans=0;
	while(!pq.empty()) {
		ans += pq.top() * i--;
		pq.pop();
	}
	cout << ans;
	return 0;
}
