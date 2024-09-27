#include <bits/stdc++.h>
using namespace std;

int sum(const string &s) {
    if(s == "") return 0;
    int ret = 0;
    for(char c: s) {
        ret += c - '0';
    }
    return ret;
}

vector<string> split(const string &str, char delim) {
    vector<string> tokens;
    string token;
    stringstream ss(str);
    while(getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int ans = 0, n=0;
    if(s.back() == '0') ans = 9;
    vector<string> v = split(s, '0');
    for(auto it = v.begin(), e=v.end();it!=e;++it) {
        ans += sum(*it);
        if(it!=e-1 && (*it)[it->size()-1]=='1') {
            ans += 9;
        }
        n += it->size();
    }
    cout << fixed << setprecision(2) << ans / ((double)n);

    return 0;
}