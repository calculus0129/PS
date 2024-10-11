#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll combo[35][35];

void fillCombo() {
    combo[0][0] = 1LL;
    for(int i=1;i<=34;++i) combo[i][0] = combo[i][i] = 1LL;
    for(int i=2,j,e;i<=34;++i) {
        for(j=1,e=i>>1;j<=e;++j) combo[i][j] = combo[i][i-j] = combo[i-1][j-1] + combo[i-1][j];
    }
}

ll ans(int s) {
    ll ret=0LL;
    for(int i=s/3+(s%3?1:0),e=s>>1;i<=e;++i) {
        ret += combo[s-i][i] * combo[s-i][i];
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T,k,s; cin >> T;
    fillCombo();
    while(T--) {
        cin >> k >> s;
        cout << k << ' ' << ans(s>>1) << '\n';
    }
    return 0;
}