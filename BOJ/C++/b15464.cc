#include <bits/stdc++.h>
using namespace std;
int inv_map[101];
int arr[101], res[101];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1, a;i<=n;++i) {
        cin >> inv_map[i];
        // cin >> a;
        // inv_map[a] = i;
    }
    for(int i=1;i<=n;++i) cin >> arr[res[i]=i];
    for(int j=3;j;--j) for(int i=1;i<=n;++i) res[i] = inv_map[res[i]];
    for(int i=1;i<=n;++i) cout << arr[res[i]] << '\n';

    return 0;
}