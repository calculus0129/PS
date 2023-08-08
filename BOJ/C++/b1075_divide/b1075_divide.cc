#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, f;
    cin >> n >> f;
    int ans;
    n/=100;
    n*=100;
    for(ans=0;ans<100 && (n+ans)%f!=0;++ans);
    cout.width(2);
    cout.fill('0');
    cout << ans;
    return 0;
}