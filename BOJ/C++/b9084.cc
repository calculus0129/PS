#include <bits/stdc++.h>
using namespace std;
int arr[10001], price[10001], n;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i=1;i<=n;++i) cin >> price[i];
        int m; cin >> m;
        memset(arr, 0, sizeof(arr));
        arr[0] = 1;
        for(int i=n,j;i>0;--i) { // The order did not matter!
            for(j=price[i];j<=m;++j) arr[j] += arr[j-price[i]];
        }
        cout << arr[m] << '\n';
    }

    return 0;
}