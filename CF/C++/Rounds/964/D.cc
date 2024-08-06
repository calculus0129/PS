#include <bits/stdc++.h>
using namespace std;

string work(string s, const string &t) {
    int m = s.size(), n = t.size(), idx = 0, i = 0;
    for(;i<m;++i) {
        if(idx<n && s[i] == t[idx]) ++idx;
        else if(s[i] == '?') {
            if(idx<n) s[i] = t[idx++];
            else s[i] = 'z';
        }
    }
    return idx == n ? s : "";
}

void solve() {
    string s, t, ans;
    cin >> s;
    cin >> t;
    ans = work(s, t);
    if(ans == "") {
        cout << "NO\n";
    } else {
        cout << "YES" << '\n' << ans << '\n';
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}