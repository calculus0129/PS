#include <bits/stdc++.h>
using namespace std;
#define MAX 2000
int primes[MAX+2];
bool isprime[MAX+2];
int D[MAX+2], P[MAX+1];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    isprime[2] = true;
    bool r;
    for(int i=3,j;i<=MAX+1;i+=2) {
        r = true;
        j = 3;
        while(r && j<i) {
            r = i%j;
            j += 2;
        }
        isprime[i] = r;
    }
    // for(int i=0;i<100;++i) if(isprime[i]) cout << i << ' ';
    for(int i=MAX;i>=1;--i) primes[i] = isprime[i] + primes[i+1];
    // for(int i=0;i<100;++i) cout << primes[i] << ' ';
    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        // vector<int> P(b+1);
        for(int i=1;i<=b;++i) P[i] = primes[i] - primes[b+1];
        for(int i=b;i>b-a;--i) D[i] = P[i];
        for(int i=b-a;i>0;--i) D[i] = P[i] - *min_element(D + (i + 1), D + (i+a+1));
        int d = (D[1]<<1) - P[1];
        cout << (d>0?"kuro":d==0?"draw":"siro") << '\n';
    }

    return 0;
}