#include <bits/stdc++.h>
using namespace std;
int main() {
    unsigned long long int a, b, c; cin >> a >> b;
    if(a>b) {
        c=a;
        a=b;
        b=c;
    }
    if(a==b) {
        cout << 0;
    }
    else {
        cout << b-a-1 << '\n';
        for(c=a+1;c<b;++c) cout << c << ' ';
    }
    return 0;
}