#include <bits/stdc++.h>
using namespace std;

string result(string st) {
    int n = st.size();
    bool surprising=true;
    for(int i=1, j;i<n && surprising;++i) {
        set<pair<char,char>> s;
        for(j=0;j<n-i;++j) {
            if(!s.empty() && s.find(make_pair(st[j], st[i+j])) != s.end()) {
                surprising=false;
                break;
            }
            s.insert({st[j], st[i+j]});
        }
    }
    return st+(surprising?" is surprising.\n":" is NOT surprising.\n");
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s = "";
    cin >> s;
    while(s!="*") {
        cout << result(s);
        cin >> s;
    }
    return 0;
}