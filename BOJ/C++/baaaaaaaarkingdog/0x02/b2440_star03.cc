#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for(i=n;i>0;--i) {
        for(j=0;j<i;++j) cout << '*';
        cout << '\n';
    }
    return 0;
}