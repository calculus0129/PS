#include <iostream>
using namespace std;
int main() {
    int n, i, j;
    cin >> n;
    for(i=1;i<=n;++i) {
        j=n-i; while(j--) cout << ' ';
        for(j=0;j<2*i-1;++j) cout << '*';
        cout << '\n';
    }
    for(i=n-1;i>0;--i) {
        j=n-i; while(j--) cout << ' ';
        for(j=0;j<2*i-1;++j) cout << '*';
        cout << '\n';
    }
    return 0;
}