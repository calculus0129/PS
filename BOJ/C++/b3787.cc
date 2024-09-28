#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, x, y, b, su;
    while(cin >> n) {
        b = su = 0;
        while(su+b < n) {
            su += b++;
        }
        x=n-su;
        y=b+1-x;
        if(b&1) swap(x, y);
        cout << "TERM " << n << " IS " << x << "/" << y << '\n';
    }
    return 0;
}