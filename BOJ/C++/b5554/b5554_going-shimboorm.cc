#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d, mn, t;
    cin >> a >> b >> c >> d;
    t = a + b + c + d;
    mn = t / 60;
    t %= 60;
    cout << mn << '\n' << t;
    return 0;
}