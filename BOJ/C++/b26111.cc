#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    LL ans=0LL;
    int cnt=1;
    for(int i=1,n=s.size();i<n;++i) {
        if(s[i] == '(') {
            ++cnt;
        } else {
            --cnt;
            if(s[i-1] == '(') {
                ans += cnt;
            }
        }
    }
    cout << ans;
    return 0;
}