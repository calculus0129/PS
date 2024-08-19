#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int a, b, n; cin >> n;
        vector<bool> discs(n);
        for(int i=0;i<n;++i) {
            cin >> a;
            discs[i] = a == 1;
        }
        a=b=0;
        for(int i=0;i<n;++i) if(discs[i]) {
            if(i&1) ++b;
            else ++a;
        }
        cout << (n&1 || abs(a-b)<2?"YES":"NO") << '\n';
    }
    return 0;
}