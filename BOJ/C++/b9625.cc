#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a = 1, b = 0, c;
    while(n--) {
        c = a+b;
        a = b;
        b = c;
    }
    cout << a << ' ' << b;
    return 0;
}