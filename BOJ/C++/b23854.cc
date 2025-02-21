#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b; cin >> a >> b;
    if(abs(a-b)%3!=0) {cout << -1; return 0;}
    // if(a>b) swap(a, b);
    int draw = a%3;
    a -= draw, b -= draw;
    cout << a/3 << ' ' << draw << ' ' << b/3;

    return 0;
}   