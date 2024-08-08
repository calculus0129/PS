#include <bits/stdc++.h>
using namespace std;

int arr[1010101], cnt[1010101];

void init() {
	for(int i=2, prev;i<=1000000;++i) {
		prev = i-1;
		if((i&1) == 0 && cnt[i>>1]<cnt[prev]) prev = i>>1;
		if(i%3 == 0 && cnt[i/3]<cnt[prev]) prev = i/3;
		cnt[i] = cnt[prev]+1;
		arr[i] = prev;
	}
}

int main() {
	init();
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cout << cnt[n] << '\n';
	for(;n;n=arr[n]) cout << n << ' ';
	return 0;
}
