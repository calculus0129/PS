#include <bits/stdc++.h>
using namespace std;

bool is_prime(int p) {
    if(p == 1 || p!=2 && (p&1)==0) return false;
    for(int q = 3;q*q<=p;q+=2) if(p%q == 0) return false;
    return true;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << (is_prime(a) && is_prime(a + b * 1000000)?"Yes":"No");
    return 0;
}