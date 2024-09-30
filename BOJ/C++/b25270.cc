#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = 99, s = 99, dist = abs(ans - n);
    for(;s<=9999;s+=100) {
        if(abs(n-s)<=dist) {
            ans = s;
            dist = abs(n-s);
        }
    }
    cout << ans;

    return 0;
}