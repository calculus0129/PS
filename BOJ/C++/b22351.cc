#include <bits/stdc++.h>
using namespace std;

bool starts_with(const string& str, const string& prefix) {
    if (prefix.size() > str.size()) {
        return false;
    }
    return str.compare(0, prefix.size(), prefix) == 0;
}

string next(const string &s) {
    string ret = "";
    int idx = s.size()-1;
    while(s[idx] == '9') --idx;
    if(idx == -1) {
        ret = "1";
        for(int i=0;i<s.size();++i) ret += '0';
    }
    else {
        ret = s;
        ret[idx]++;
        for(int i=idx+1;i<s.size();++i) ret[i]='0';
    }
    return ret;
}

// bool starts_with(string_view str, string_view prefix) {
//     return str.substr(0, prefix.size()) == prefix;
// }

pair<bool, pair<string, string>> work(const string &s) {
    int ret=1,n=s.size();
    string r1="", r2="";
    bool r=false;
    for(;ret<n;++ret) {
        string tmp=s, m = s.substr(0UL, ret);
        r1=m;
        while(!tmp.empty() && starts_with(tmp, m)) {
            r2 = tmp;
            tmp = tmp.substr(m.size());
            m = next(m);
        }
        if(tmp.empty()) {
            r=true;
            break;
        }
    }
    return {r, {r1, r2}};
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    auto [b, p] = work(s);
    cout << (b?(p.first + ' ' + p.second):s+' '+s);
    
    return 0;
}

/*
123681294

1
12
123
1236
12368
123681
1236812
12368129
 */