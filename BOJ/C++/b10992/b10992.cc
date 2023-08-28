#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=n-1;i>0;--i) cout << ' ';
    if(n!=1) cout << "*\n";
    for(int i=1, t;i<n-1;++i) {
        t=n-1-i;
        while(t--) cout << ' ';
        cout << '*';
        t=2*i-1;
        while(t--) cout << ' ';
        cout << "*\n";
    }
    for(int i=2*n-1;i>0;--i) cout << '*';
    return 0;
}