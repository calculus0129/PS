#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int cnt=0,n;
        string s;
        cin >> n;
        cin >> s;
        bool is0 = false;
        for(char c: s) if(!(c == '0' && is0)) {
            if(c == '0') {
                cnt--;
                is0 = true;
            } else {
                cnt++;
                is0 = false;
            }
        }
        cout << (cnt>0?"YES":"NO") << '\n';
    }

    return 0;
}