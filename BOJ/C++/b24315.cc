#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, c1, c2, n;
    cin >> a >> b >> c1 >> c2 >> n;
    cout << (c1<=a && a<=c2 && c1*n <= a*n + b && a*n + b <= c2*n);
    return 0;
}