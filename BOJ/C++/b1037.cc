#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return (size_t)a*b/gcd(a, b);
}

bool ispow(int base, int num) {
    if(num == 1) return true;
    else if(num%base) return false;
    return ispow(base, num/base);
}

bool isprime(int p) { // 최대 2^16 = 32768
    for(int i=2;i<p;++i) if(p%i == 0) return false;
    return true;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int a; cin >> a;
    int ans = a;
    int mn = a;

    for(int i=1;i<n;++i) {
        cin >> a;
        ans = lcm(a, ans);
        mn = min(a, mn);
    }
    if(ispow(mn, ans) && isprime(mn)) ans *= mn;

    cout << ans;

    return 0;
}