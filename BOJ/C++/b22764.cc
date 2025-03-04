#include <bits/stdc++.h>
using namespace std;

vector<char> btn[10] = {
    {},
    {'.', ',', '!', '?', ' '},
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'},
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // for(int i=0;i<10;++i) {
    //     cout << "btn " << i << ": ";
    //     for(char c: btn[i]) {
    //         cout << c << '\t';
    //     }
    //     cout << '\n';
    // }
    int T, cnt, idx; cin >> T;
    string s;
    while(T--) {
        cin >> s;
        cnt = 0;
        for(char c: s) {
            if(c == '0') {           
                if(cnt) {
                    cout << btn[idx][(cnt-1) % btn[idx].size()];
                    cnt = 0;
                }
            }
            else {
                idx = c - '0';
                ++cnt;
            }
        }
        cout << '\n';
    }

    return 0;
}