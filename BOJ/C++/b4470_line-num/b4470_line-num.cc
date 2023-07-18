#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    char s[52];
    cin.clear();
    cin.getline(s, 51);
    for(int i=1;i<=n;++i) {
        cin.getline(s, 51);
        cout << i << ". " << s << '\n';
    }

    return 0;
}