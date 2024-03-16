#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    char arr[11][11];
    for(int i=0, j;i<m;++i) for(j=n-1;j>=0;--j) scanf(" %c", &arr[i][j]);
    for(int i=0, j;i<m;++i) {
        for(j=0;j<n;++j) cout << arr[i][j];
        cout << '\n';
    }
}