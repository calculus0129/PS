#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int r, f;
    cin >> r >> f;
    f %= (r<<1);
    f<<=1;
    cout << ((f>r && f<(3*r))?"down":"up");

    return 0;
}