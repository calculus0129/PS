#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for(i=1;i<=2*n-1;i+=2) {
        for(j=0;j<(i+1)/2-1;++j) cout<<' ';
        for(j=0;j<2*n-i;++j) cout<<'*';
        cout << '\n';
    }
    return 0;
}