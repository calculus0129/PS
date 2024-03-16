#include <bits/stdc++.h>
#define EUCMOD(a,m) ((a)%(m)+(m))%(m)
using namespace std;
typedef long long int lli;
const lli M = 1000000007LL;

long long modmul(const lli a, const lli b) {
    return EUCMOD(a*b, M);
}

lli modfact(lli a) {
    lli ret = 1LL;
    while(a>0LL) {
        ret = modmul(ret, a--);
    }
    return ret;
}

lli pow(lli a, lli e) {
    lli ret = 1LL, m = a;
    do {
        if(e&1LL) ret = modmul(ret, m);
        m = modmul(m, m);
    } while(e>>=1);

    return ret;
}

lli inv(lli a) {
    return pow((lli)a, M-2LL);
}

lli combo(lli n, lli r) {
    return modmul(modfact(n),inv(modfact(n-r)))*inv(modfact(r))%M;
}

int main() {
    lli n, k;
    cin >> n >> k;
    cout << (lli)combo(n, k);
    return 0;
}