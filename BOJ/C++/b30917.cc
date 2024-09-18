#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    int a=0, b=0, tmp;
    bool r = false;
    while(!r && ++a<9) {
        cout << "? A " << a << endl;
        cin >> tmp;
        r = tmp == 1;
    }
    r = false;
    while(!r && ++b<9) {
        cout << "? B " << b << endl;
        cin >> tmp;
        r = tmp == 1;
    }
    cout << "! " << a+b;
    return 0;
}