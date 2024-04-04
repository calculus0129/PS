#include <bits/stdc++.h>
using namespace std;
bool cantor[1010100];
int pow(int base, int exp) {
    int ret=1, m=base;
    do {
        if(exp&1) ret *= m;
        m *= m;
    } while(exp>>=1);
    return ret;
}
void work(int n, int start) {
    if(n==0) return;
    memset(cantor+n/3+start, 0, n/3);
    work(n/3, start);
    work(n/3, start+(n/3<<1));
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    // https://www.acmicpc.net/board/view/120317
    while(cin >> n) {
        n = pow(3, n);
        memset(cantor, 1, n);
        work(n, 0);
        for(int i=0;i<n;++i) cout << (cantor[i]?'-':' ');
        cout << '\n';
    }
    return 0;
}