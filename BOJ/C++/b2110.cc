#include <bits/stdc++.h>
using namespace std;
int arr[202020], n, c;
bool visited[202020];

bool check(int d) {
	int cnt=1, last=arr[0];
	memset(visited, 0, sizeof visited);
	for(int i=1;i<n;++i) {
		if(arr[i]<last+d) continue;
		++cnt;
		last = arr[i];
	}
	return cnt>=c;	
}

int work() {
	int mid, lo = 1, hi=1000000001;
	while(lo+1<hi) {
		mid = lo+hi>>1;
		if(check(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return lo;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> c;
	for(int i=0;i<n;++i) cin >> arr[i];
	sort(arr, arr+n);
	cout << work();
	return 0;
}
