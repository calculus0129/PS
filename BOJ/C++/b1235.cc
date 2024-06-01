#include <bits/stdc++.h>
using namespace std;
char stu[1010][101];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, len, k, i; cin >> n;
    unordered_set<string> s;
    for(i=0;i<n;++i) cin >> stu[i];
    len = strlen(stu[0]);
    for(k=1;k<len;++k) {
        s.clear();
        for(i=0;i<n;++i) {
            string tmp = string(&stu[i][len-k]);
            if(s.find(tmp) != s.end()) break;
            s.insert(tmp);
        }
        if(i==n) break;
    }
    cout << k;

    return 0;
}