#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int ans=0, mi = INT_MAX;
    if(n<10) ans=1;
    else {
        if((n&1) == 1) {
            n-=9;
            ans=1;
        } else {
            mi = 1 + (((n-8)/18+((n-8)%18?1:0))<<1);
        }
        ans += min(mi, (n/18+(n%18?1:0))<<1);
    }
    cout << ans;
    return 0;
}