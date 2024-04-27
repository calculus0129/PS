#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    unsigned int x, y; cin >> x >> y;
    y = y-x;
    unsigned int ans=0;
    while(ans*(ans+1)<y) ++ans;
    if(ans>0 && ans*ans>=y) ans = (ans<<1)-1;
    else ans <<= 1;
    cout << ans;
    
    return 0;
}