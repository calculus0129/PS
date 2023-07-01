#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i, j;
    for(i=1;i<=n;++i) {
        j=i; while(j--) cout << '*';
        j=2*(n-i); while(j--) cout << ' ';
        j=i; while(j--) cout << '*';
        cout << '\n';
    }
    for(i=n-1;i>0;--i) {
        j=i; while(j--) cout << '*';
        j=2*(n-i); while(j--) cout << ' ';
        j=i; while(j--) cout << '*';
        cout << '\n';
    }
}