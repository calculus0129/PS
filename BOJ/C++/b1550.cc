#include <bits/stdc++.h>
using namespace std;

int convert(string s) {
    int ret = 0;
    for(auto i = s.begin(), e = s.end();i!=e;++i) {
        ret <<= 4;
        char c = *i;
        ret += ((c<='9')?c-'0':c-'A'+10);
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << convert(s);

    return 0;
}