#include <bits/stdc++.h>
using namespace std;
map<string,string> pw;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    while(m--) {
        string s, t; cin >> s >> t;
        pw[s] = t;
    }
    while(n--) {
        string s; cin >> s;
        cout << pw[s] << '\n';
    }
    return 0;
}