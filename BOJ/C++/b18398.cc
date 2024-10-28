#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    int a, b, n;
    while(T--) {
        cin >> n;
        while(n--) {
            cin >> a >> b;
            cout << a + b << ' ' << a*b << '\n';
        }
    }
    return 0;
}