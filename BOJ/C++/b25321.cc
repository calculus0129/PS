#include <bits/stdc++.h>
// #define ADD(x,y) ((x)+(y))%BIG
// #define NEG(x) (BIG-(x))%BIG
// #define SUB(x,y) ADD((x),NEG(y))
// #define MUL(x,y) (x)*(y)%BIG
using namespace std;
typedef long long ll;
const ll BIG = 1000000007LL;

struct Lucas{ // init : O(P), query : O(log P)
    const size_t P;
    vector<ll> fac, inv;
    ll Pow(ll a, ll b) {
        ll res=1;
        b%=P-1;
        while(b<0) b += P-1;
        for(; b; b>>=1, a=a*a%P) if(b & 1) res = res * a % P;
        return res;
    }
    Lucas(size_t P, size_t N) : P(P), fac(N), inv(N) {
        fac[0]=1; for(int i=1;i<N;i++) fac[i]=fac[i-1]*i%P;
        inv[N-1] = Pow(fac[N-1], P-2);
        for(int i=N-2;~i;i--) inv[i]= inv[i+1] * (i+1) % P;
    }
    ll small(ll n, ll r) const {
        return r<=n ? fac[n] * inv[r] % P * inv[n-r] % P : 0LL;
    }
    ll calc(ll n, ll r) const {
        if(n<r || n<0 || r<0) return 0LL;
        if(!n || !r || n==r) return 1LL;
        return small(n%P, r%P) * calc(n/P, r/P) % P;
    }
} L(BIG, 151000);

ll catalan(ll cnt) {
    return L.small(cnt<<1, cnt) * L.Pow(cnt+1, BIG-2) % BIG;
}

int counts[101010];
stack<ll> nums;

ll work() {
    vector<ll> arr;
    // !nums.empty() && 
    while(!nums.empty() && nums.top()!=-1) {
        ll num = nums.top(); nums.pop(); arr.push_back(num);
    }
    ll ret = catalan(arr.size());
    for(ll num: arr) {
        ret = ret * num % BIG;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int cnt = 0, depth = 0, max_depth = 0;
    bool question=false;
    for(char c: s) {
        switch(c) {
        case '?':
            nums.push(-1);
            break;
        case ':':
            ll num = work();
            nums.pop(); // popping -1.
            nums.push(num);
        }
    }
    cout << work();
    return 0;
}