#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    long long ans = 0LL;
    int n; cin >> n;
    for(int a=(n-1>>1),ea=(n+2)/3;a>=ea;--a) {
        ans += (3*a-n>>1)+1;
    }
    cout << ans;
    return 0;
}