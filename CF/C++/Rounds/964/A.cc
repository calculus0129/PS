#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int s;
    while(t--) {
        cin >> s;
        cout << s%10 + s/10 << '\n';
    }

    return 0;
}