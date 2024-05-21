#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0, j;i<(n<<1);++i) {
        for(j=0;j<n;++j) {
            cout << ((i+j&1) == 0?'*':' ');
        }
        cout << '\n';
    }

    return 0;
}