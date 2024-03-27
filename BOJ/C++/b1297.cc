#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int d, h, w;
    cin >> d >> h >> w;
    double mul = d/sqrt(h*h+w*w);
    cout << floor(mul*h) << ' ' << floor(mul*w);
    return 0;
}