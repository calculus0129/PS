#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i,j;
    for(i=0;i<n;++i) {
        j=i; while(j--) cout << ' ';
        j=2*(n-i)-1; while(j--) cout << '*';
        cout << '\n';
    }
    for(i=n-2;i>=0;--i) {
        j=i; while(j--) cout << ' ';
        j=2*(n-i)-1; while(j--) cout << '*';
        cout << '\n';
    }
}