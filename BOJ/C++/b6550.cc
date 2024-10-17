#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string inp;
    string s, t;
    while(getline(cin, inp)) {
        // cin.clear();
        // cin.ignore();
        istringstream iss(inp);
        iss >> t >> s;
        int m=t.size(), j=0;
        for(int i=0,n=s.size();i<n && j<m;++i) {
            if(s[i]==t[j]) ++j;

        }
        cout << (j==m?"Yes\n":"No\n");
    }
    return 0;
}