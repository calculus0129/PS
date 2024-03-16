#include <bits/stdc++.h>
using namespace std;

int s[1000001];

int find(int n) {
    if(s[n] == n) return n;
    return s[n] = find(s[n]);
}

int unionize(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa != fb) s[fa] = s[fb] = min(fa, fb);
    return s[fa];
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int n, m, q, a, b;
    cin >> n;
    for(int i=1;i<=n;++i) s[i] = i;
    for(cin >> m;m>0;--m) {
        cin >> q >> a >> b;
        if(q == 0) {
            unionize(a, b);
        } else {
            cout << (find(a) == find(b)?"YES\n":"NO\n");
        }
    }

    return 0;
}