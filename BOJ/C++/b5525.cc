#include <bits/stdc++.h>
using namespace std;

vector<int> fail(const string &w) {
    int n = w.size();
    vector<int> f(n, 0);
    for(int i=1,j=0;i<n;++i) {
        while(j>0 && w[i]!=w[j]) j = f[j-1];
        if(w[i]==w[j]) f[i] = ++j;
    }
    return f;
}

int solve(const string &s, const string &w) {
    int ret = 0;
    auto f = fail(w);
    for(int i=0,j=0,n=s.size(),m=w.size();i<n;++i) {
        while(j>0 && s[i]!=w[j]) j = f[j-1];
        if(s[i] == w[j]) ++j;
        if(j == m) {
            ++ret;
            j = f[j-1];
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string w="I";
    while(n--) w+="OI";
    cin >> n;
    string s; cin >> s;
    cout << solve(s, w) << '\n';

    return 0;
}