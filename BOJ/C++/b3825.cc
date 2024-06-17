#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a*b==0) return 0;
    int c;
    if(a>b) {
        c = a;
        a = b;
        b = c;
    }
    while(a!=0) {
        c = b%a;
        b = a;
        a = c;
    }
    return b;
}

struct bank {
    int x, y;
    int magsq() {
        return x*x+y*y;
    }
    bool factorOf(bank other) {
        return other.magsq()>0 && (x*other.x + y*other.y) % magsq() == 0 && (x*other.y-y*other.x) % magsq() == 0;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int m, n, p, q;
    bool r;
    while(t--) {
        cin >> p >> q;
        if(p<0) p = -p;
        if(q<0) q = -q;
        // It's equivalent to see if (|p|, |q|) is prime.
        if(p>q) {
            m = p;
            p = q;
            q = m;
        }
        if(p*p+q*q<=1 || gcd(p, q)>1) {
            cout << "C\n";
            continue;
        }
        bank bp = {p, q};
        r = true;
        if(p == 0) for(n=2;r && n<q;++n) if(q%n == 0) r = false;
        for(m=1;r && m*m<20000;++m) {
            for(n=1;r && m*m+n*n<20000;++n) {
                if(bank({m,n}).factorOf(bp) && (m!=p || n!=q)) {
                    r = false;
                }
            }
        }
        cout << (r?"P\n":"C\n");
    }
    return 0;
}