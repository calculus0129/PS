#include <bits/stdc++.h>
using namespace std;
int a[1001], b[1001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i] >> b[i];
    int idx = min_element(b, b+n) - b;
    cout << a[idx] << ' ' << b[idx];
    return 0;
}