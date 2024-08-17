#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=n-1,j=n-1;i>1;i=--j) {
		while(j>1 && (s[j]=='4' || s[j]=='5')) --j;
		if(s.substr(j-1, 2) == "PS") s.erase(j+1,i-j);
	}
	cout << s;
	
	return 0;
}
