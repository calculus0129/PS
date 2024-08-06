#include <bits/stdc++.h>
#define P 1000000007LL
#define MUL(a,b) ((a)*(b)%P)
using namespace std;
typedef long long ll;
ll fact[201010];
ll inv_fact[201010];

ll power(ll b, ll e) {
    ll ret = 1LL;
    for(; e; e>>=1, b = MUL(b, b)) if(e & 1LL) ret = MUL(ret, b);
    return ret;
}

ll combo(ll n, ll r) {
    if(n<r || r<0LL) return 0LL;
    return MUL(MUL(fact[n], inv_fact[n-r]), inv_fact[r]);
}

void init() {
    fact[0] = 1LL;
    for(int i=1;i<=200000;++i) {
        fact[i] = MUL(fact[i-1], i);
    }
    inv_fact[200000] = power(fact[200000], P-2LL);
    for(int i=199999;~i;--i) inv_fact[i] = MUL(inv_fact[i+1], i+1);
}

int main() {
    char c;
    init();
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, n, k, cnt[2]; cin >> T;
    ll ans;
    while(T--) {
        cin >> n >> k;
        cnt[0]=cnt[1]=0;
        for(int i=n;i>0;--i) {
            cin >> c;
            cnt[c=='1']++;
        }
        ans = 0LL;
        for(int i=(k>>1)+1;i<=cnt[1];++i) {
            ans += MUL(combo(cnt[0], k-i), combo(cnt[1], i));
            ans %= P;  // Apply modulo here to prevent overflow
        }
        cout << ans << '\n';
    }
    return 0;
}