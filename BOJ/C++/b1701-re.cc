#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0, i, j, n, k;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    n = s.size();
    for(i=0;i+ans<n;++i) {
        vector<int> fail(n-i);
        k=0;
        for(j=1;i+j<n;++j) {
            while(k>0 && s[i+j] != s[i+k]) k=fail[k-1];
            if(s[i+j] == s[i+k]) fail[j] = ++k;
        }
        ans = max(ans, *max_element(fail.begin(), fail.end()));
    }
    cout << ans;
    return 0;
}