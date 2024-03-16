#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, j; cin >> n;
    for(i=1;i<=n;++i) {
        for(j=i;j>0;--j) cout << '*';
        cout << '\n';
    }
    for(i=n-1;i>0;--i) {
        for(j=i;j>0;--j) cout << '*';
        cout << '\n';
    }
    return 0;
}