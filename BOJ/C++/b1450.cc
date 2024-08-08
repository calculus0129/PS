#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
vector<ll> bf(const ll *ptr, int n) {
	if(n == 0) return vector<ll>{0LL};
	vector<ll> ret(1<<n);
	ret[0] = 0LL;
	ret[1] = *ptr;
	for(int i=1, j, s;i<n;++i) {
		for(j=0,s=1<<i;j<s;++j) {
			ret[j+s] = ret[j] + *(ptr+i);
		}
	}
	sort(ALL(ret));
	return ret;	
}

ll arr[30];

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	ll c, ans = 0LL;
	int n; cin >> n >> c;
	for(int i=0;i<n;++i) cin >> arr[i];
	vector<ll> a1 = bf(arr, n>>1);
	vector<ll> a2 = bf(arr+(n>>1), n-(n>>1));
	int j = 0, sz = a1.size();
	for(auto it = a2.rbegin(), e = a2.rend();it!=e;++it) {
		while(j<sz && a1[j]+*it<=c) ++j;
		ans += j;
	}
	cout << ans;

	return 0;
}
