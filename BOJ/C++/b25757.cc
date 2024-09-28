#include <bits/stdc++.h>
using namespace std;
set<string> a;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int m, n; char c;
	cin >> n >> c;
	switch(c) {
		case 'Y':
			m = 1;
			break;
		case 'F':
			m = 2;
			break;
		default:
			m = 3;
	}	
	string s;
	while(n--) {
		cin >> s;
		a.insert(s);
	}
	cout << a.size()/m;
	return 0;
}
