#include <bits/stdc++.h>
using namespace std;
void print(int n) {
    cout << 'I';
    for(int i=0,e=n<<1|1;i<e;++i) cout << (i&1?'X':'-');
    cout << 'I';
}
void edge(int n) {
    cout << '+';
    for(int i=0,e=n<<1|1;i<e;++i) cout << '-';
    cout << '+';
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    edge(m); cout << "          "; edge(n); cout << '\n';
    for(int i=0,e=1+max(m, n), j;i<e;++i) {
        if(i<=m) {
            if(i==m) edge(m);
            else print(m);
        }
        if(i<=n) {
            cout << "          ";
            if(i>m) for(j=0;j<2*m+3;j++) cout << ' ';
            if(i==n) edge(n);
            else print(n);
        }
        cout << '\n';
    }
    return 0;
}