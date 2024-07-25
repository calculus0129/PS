#include <bits/stdc++.h>
using namespace std;
int arr[301][301];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) {
        int a;
        cin >> a;
        arr[i][j] = arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]+a;
    }
    int k; cin >> k;
    while(k--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--;
        cout << arr[c][d] - arr[a][d] - arr[c][b] + arr[a][b] << '\n';
    }


    return 0;
}