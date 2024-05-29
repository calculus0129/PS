#include <bits/stdc++.h>
using namespace std; // https://velog.io/@yawn11/cout-fixed-cout.precision
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    double a;
    int n; cin >> n;
    cout<<fixed;
    cout.precision(2);
    while(n--) {
        cin >> a;
        cout << '$' << a*0.8 << '\n';
    }

    return 0;
}