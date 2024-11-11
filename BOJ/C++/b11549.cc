#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int cnt = 0;
    if(a == n) cnt++;
    if(b == n) cnt++;
    if(c == n) cnt++;
    if(d == n) cnt++;
    if(e == n) cnt++;
    cout << cnt;

    return 0;
}