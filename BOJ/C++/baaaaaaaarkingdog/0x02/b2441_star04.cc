#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for(i=0;i<n;++i) {
        for(j=0;j<i;++j) cout<<' ';
        for(;j<n;++j) cout << '*';
        cout << '\n';
    }
    return 0;
}