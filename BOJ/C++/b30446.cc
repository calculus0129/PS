#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p10(int n) {
    int ret = 1;
    while(n--) ret *= 10;
    return ret;
}

bool allowPalindrome(const string &s) {
    int n = s.size()-1;
    for(int i=(n-1>>1);~i;--i) if(s[i]!=s[n-i]) return s[i]<s[n-i];
    return true;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    // istringstream ss(s);
    // ll N; ss >> N;
    int n = s.size()-1;
    int ans = 0;
    
    for(int i=1;i<=n;++i) {
        ans += 9*p10(i-1>>1);
    }

    for(int i=0,ep=(n>>1);~ep;++i,--ep) {
        ans += (s[i]-'0')*p10(ep);
    }
    ans -= p10(n>>1);

    ans += allowPalindrome(s);

    cout << ans;

    return 0;
}