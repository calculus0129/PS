#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    LL n; cin >> n;
    int r=2;
    while(n) {
        r = n % 3;
        if(r & 2LL) break;
        n /= 3LL;
    }
    cout << (r != 2 ? "YES" : "NO");

    return 0;
}