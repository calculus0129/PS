#include <bits/stdc++.h>
using namespace std;

vector<int> failure(const string &s) {
    int n = s.size();
    vector<int> f(n);
    for(int i=1,j=0;i<n;++i) {
        while(j>0 && s[j] != s[i]) j = f[j-1];
        if(s[j] == s[i]) f[i] = ++j;
    }
    return f;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string t, s;
    getline(cin, t);
    getline(cin, s);
    vector<int> f = failure(s);
    vector<int> ans;

    for(int i=0,n=t.size(),m=s.size(),j=0;i<n;++i) {
        while(j>0 && s[j] != t[i]) j = f[j-1];
        if(s[j] == t[i]) ++j;
        if(j == m) {
            ans.push_back(i+1-m+1);
            j = f[m-1];
        }
    }

    cout << ans.size() << '\n';
    for(int i: ans) cout << i << ' ';    

    return 0;
}