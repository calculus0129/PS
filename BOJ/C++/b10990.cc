#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0, j;i<n;++i) {
        for(j=i;j<n-1;++j) cout << ' ';
        cout << '*';
        if(i == 0) {
            cout << '\n';
            continue;
        }
        for(j=0;j<2*i-1;++j) cout << ' ';
        cout << "*\n";
    }
    return 0;
}