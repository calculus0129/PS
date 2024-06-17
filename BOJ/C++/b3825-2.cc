#include <bits/stdc++.h>
using namespace std;
int p, q;

bool isdivisible(int p, int q, int m, int n) {
    return (p*m+n*q) % (m*m+n*n) == 0 && (-p*n+q*m) % (m*m+n*n) == 0;
}

bool prime(int p, int q) {
    int m, n;
    if(p>q) swap(p, q);
    if(p*p+q*q<=1) return false;
    for(n=2;n*n<20000;++n) if(isdivisible(p, q, 0, n) && (p!=m || q!=n)) return false;
    for(m=1;m*m<20000;++m) for(n=1;m*m+n*n<20000;++n) if(isdivisible(p, q, m, n) && (p!=m || q!=n)) return false;
    return true;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        cin >> p >> q;
        cout << (prime(abs(p), abs(q))?"P\n":"C\n");
    }
    return 0;
}