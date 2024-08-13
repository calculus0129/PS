#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    string s;
    bool r = true;
    while(t--) {
        r = true;
        cin >> s;
        if(s.size()<3 || s.substr(0, 2) != "10") r = false;
        else {
            s = s.substr(2);
            if(s[0] == '0' || s == "1") r = false;
            else r = true;
        }
        cout << (r?"YES\n":"NO\n");
    }
    return 0;
}