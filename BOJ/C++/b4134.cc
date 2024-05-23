#include <bits/stdc++.h>
using namespace std;

bool odd_isprime(unsigned int n) {
    for(unsigned int i=3;i*i<=n;++i) if(n%i==0) return false;
    return true;
}

unsigned int lbp(unsigned int m) {
    if(m<=2U) return 2;
    unsigned int p=m|1;
    while(!odd_isprime(p)) p+=2;
    return p;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    unsigned int m;
    while(n--) {
        cin >> m;
        cout << lbp(m) << '\n';
    }
    return 0;
}