#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    int a, b, ans=1001;
    while(t--) {
        cin >> a >> b;
        if(a<=b) ans = min(ans, b);
    }
    cout << (ans==1001?-1:ans);
}