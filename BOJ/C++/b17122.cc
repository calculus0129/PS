#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        char s[3];
        cin >> s;
        int num; cin >> num;
        cout << (((s[1]-'1'&1)+(s[0]-'A'&1)&1) == ((num-1)/8 % 2 + ((num-1) & 1) & 1) ? "YES" : "NO") << '\n';
    }
    return 0;
}