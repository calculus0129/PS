#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=2;i<=n;++i) arr[1][i] += arr[1][i-1];
    for(int i=2,j;i<=m;++i) {
        vector<int> l(n+1), r(n+1);
        for(j=1;j<=n;++j) {
            l[j] = r[j] = arr[i][j] + arr[i-1][j];
        }
        // Add to Right
        for(j=2;j<=n;++j) {
            l[j] = max(l[j], l[j-1]+arr[i][j]);
        }
        // Add to Left
        for(j=n-1;j;--j) {
            r[j] = max(r[j], r[j+1]+arr[i][j]);
        }
        for(j=1;j<=n;++j) {
            arr[i][j] = max(l[j], r[j]);
        }
    }
    cout << arr[m][n];
    return 0;
}