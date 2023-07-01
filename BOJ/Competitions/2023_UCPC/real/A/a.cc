#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int i, a, s=0;
    for(i=0;i<10;++i) {
        cin >> a;
        s+=a;
    }
    switch(s%4) {
        case 0:
            cout << 'N';
            break;
        case 1:
            cout << 'E';
            break;
        case 2:
            cout << 'S';
            break;
        default:
            cout << 'W';
            break;   
    }
    return 0;
}