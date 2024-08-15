#include <bits/stdc++.h>
using namespace std;

vector<int> f(const string &s) {
	int n = s.size();
	vector<int> arr(n);
	for(int i=1,j=0;i<n;++i) {
		while(j>0 && s[i] != s[j]) j = arr[j-1];
		if(s[i] == s[j]) arr[i] = ++j;
	}
	return arr;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int l; cin >> l;
	string s; cin >> s;
	cout << l-f(s)[l-1];
	return 0;
}
