#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    if(n%4==0 && (n%400==0 || n%100!=0)) cout << 1;
    else cout << 0;
    return 0;
}