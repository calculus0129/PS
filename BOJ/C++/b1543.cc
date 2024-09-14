#include <bits/stdc++.h>
using namespace std;
vector<int> failure(const string &w) {
    int j=0,n=w.size();
    vector<int> f(n);
    for(int i=1;i<n;++i) {
        while(j>0 && w[i]!=w[j]) j = f[j-1];
        if(w[i] == w[j]) f[i] = ++j;
    }
    return f;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s, w;
    getline(cin, s);
    getline(cin, w);
    vector<int> fw = failure(w);
    int i=0,j=0,m=s.size(), n = w.size(), ans = 0;
    for(;i<m;++i) {
        while(j>0 && s[i] != w[j]) j = fw[j-1];
        if(s[i] == w[j]) ++j;
        if(j == n) {
            ++ans;
            j = 0;
        }
    }
    cout << ans;

    return 0;
}