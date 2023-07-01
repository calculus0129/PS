#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d, n=3;
    while(n--) {
        cin >> a >> b >> c >> d;
        switch(a+b+c+d) {
            case 0:
                cout << 'D';
                break;
            case 1:
                cout << 'C';
                break;
            case 2:
                cout << 'B';
                break;
            case 3:
                cout << 'A';
                break;
            case 4:
                cout << 'E';
                break;
        }
        cout << '\n';
    }
    return 0;
}