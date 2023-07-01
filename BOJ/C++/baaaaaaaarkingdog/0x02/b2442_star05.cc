#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for(i=n-1;i>=0;--i) {
        for(j=0;j<i;++j) cout<<' ';
        for(j=0;j<2*(n-i)-1;++j) cout << '*';
        cout << '\n';
    }
    return 0;
}