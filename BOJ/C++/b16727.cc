#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a, b, c, d; cin >> a >> b >> c >> d;
    if(a+d > b + c) {
        cout << "Persepolis";
    }
    else if(b + c > a + d) {
        cout << "Esteghlal";
    }
    else {
        if(b!=d) {
            if(b>d) {
                cout << "Esteghlal";
            } else {
                cout << "Persepolis";
            }
        } else {
            cout << "Penalty";
        }
    }
    return 0;
}