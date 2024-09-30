#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	cin >> s;
	int halls=0, jjaks=0;
	for(char c: s) {
		if(c-'0'&1) {
			halls++;
		} else {
			jjaks++;
		}
	}
	cout << (jjaks>halls?0:halls>jjaks?1:-1);
	return 0;
}
