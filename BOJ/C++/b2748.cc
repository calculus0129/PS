#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    lli a=0LL, b=1LL, t;
    cin >> n;
    while(n--) {
        t = a;
        a = b;
        b = b+t;
    }
    cout << a;

    return 0;
}