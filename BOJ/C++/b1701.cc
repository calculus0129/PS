#include <bits/stdc++.h>
using namespace std;

vector<int> failure(const string &s) {
    int j = 0, n = s.size();
    vector<int> ret(n);
    for(int i=1;i<n;++i) {
        while(j>0 && s[i] != s[j]) j = ret[j-1];
        if(s[j] == s[i]) ret[i] = ++j;
    }
    return ret;
}

bool work(const string &s, int i, int j, const vector<int> &f) {
    // string sub = s.substr(i, j-i);
    // vector<int> f = failure(sub);
    int n=s.size(),m=j-i;
    j=0;
    // map<int,int> freq;
    int cnt = 0;
    for(int k=0;k<n && cnt<2;++k) {
        while(j>0 && s[k] != s[i+j]) {
            j = f[j-1];
        }
        if(s[k] == s[i+j]) ++j;
        // freq[j]++;
        if(j == m) {
            ++cnt;
            j = f[j-1];
        }
    }
    return cnt>1;
}

int solve(const string &s) {
    int n = s.size(), ans=0,i,j;
    vector<vector<int>> failures(n);
    for(i=0;i<n;++i) failures[i] = failure(s.substr(i));
    i=0;
    for(j=1;j<=n;++j) {
        if(work(s, i, j, failures[i])) {
            ans = j-i;
        } else {
            ++i;
        }
    }
    return ans;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    cout << solve(s);

    return 0;
}