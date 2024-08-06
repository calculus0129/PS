#include <bits/stdc++.h>
using namespace std;
int arr[101010], n;
typedef long long ll;

ll work(int s, int e) {
	if(s == e) return arr[s];
	int mid = s + e >> 1;
	ll ret = max(work(s, mid), work(mid+1, e));
	int h = min(arr[mid], arr[mid+1]), i=mid, j=mid+1;
	while(i>s || j<e) {
		while(i>s && arr[i-1]>=h) --i;
		while(j<e && arr[j+1]>=h) ++j;
		ret = max(ret, (j-i+1)*(ll)h);
		if(j<e && (i==s || arr[j+1]>=arr[i-1])) h = arr[++j];
		else if(i>s) h = arr[--i];
	}
	ret = max(ret, (j-i+1)*(ll)h);
	return ret;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;
	while(n) {
		for(int i=0;i<n;++i) cin >> arr[i];
		cout << work(0, n-1) << '\n';
		cin >> n;
	}
	return 0;
}
