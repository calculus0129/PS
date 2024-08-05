#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[1010];
int main() 
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n, m, i=0; cin >> n >> m;
	ll ans=0LL;
	while(n--) {
		int a; cin >> a;
		arr[i]++;
		i = (m+i-(a%m))%m;
		ans += arr[i];
	}
	cout << ans;
	return 0;
}
