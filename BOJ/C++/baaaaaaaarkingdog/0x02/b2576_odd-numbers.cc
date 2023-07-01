#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int mn=101, n, i=7, sum=0;
    while(i--) {
        cin >> n;
        if(n%2==1) {
            sum+=n;
            if(n<mn) mn=n;
        }
    }
    if(mn==101) cout << -1;
    else cout << sum << '\n' << mn;
    return 0;
}