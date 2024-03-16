#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, a=0, b=1, t;
    cin >> n;
    for(int i=1;i<n;++i) {
        t = a;
        a = b;
        b += t;
    }
    cout << b << ' ' << n-2;

    return 0;
}