#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SZ=1<<17;
ll ans;

// Lazy Propagating Segment Tree
class LPST {
public:
    // equivalent to lazy_update, etc.
    void Push(int node, int s, int e) {
        if(L[node] == 0) return;
        T[node] += (e-s+1)*L[node];
        if(s != e) L[node<<1] += L[node], L[node<<1|1] += L[node];
        L[node]=0;
    }
    ll T[SZ<<1], L[SZ<<1];
    LPST() {
        memset(T, 0, sizeof T);
        memset(L, 0, sizeof L);
    }
    // LPST(const vector<ll> &arr, int st=0, int end=INT_MAX) {
    //     memset(T, 0, sizeof T);
    //     memset(L, 0, sizeof L);
    //     end=max(arr.size(), (size_t)end);
    //     for(int i=st,n=end;i<n;++i) T[i+SZ]=arr[i];
    //     //initialization
    //     for(int i=17,j,e;i>=0;--i) {
    //         for(j=0,e=1<<i;j<e;++j) {
    //             T[e+j] = T[e+j>>1] + T[e+j>>1|1];
    //         }
    //     }
    // }

    // [l,r]번째 수에 v를 더함,0<=l<=r<SZ
    void RangeAdd(int l, int r, ll v, int node=1, int s=0, int e=SZ-1) {
        Push(node, s, e);
        if(r<s || e<l || r<l) return;
        if(l<=s && e<=r) {
            L[node] += v;
            Push(node, s, e);
            return;
        }
        int m = s+e>>1;
        RangeAdd(l, r, v, node<<1, s, m);
        RangeAdd(l, r, v, node<<1|1, m+1, e);
        T[node] = T[node<<1] + T[node<<1|1];
    }

    ll RangeSum(int l, int r, int node = 1, int s = 0, int e = SZ-1) {
        Push(node, s, e);
        if(r<s || e<l) return 0LL;
        if(l<=s && e<=r) return T[node];
        int m = s+e>>1;
        return RangeSum(l, r, node<<1, s, m) + RangeSum(l, r, node<<1|1, m+1, e);
    }

    ll operator[](int idx) {
        return RangeSum(idx, idx);
    }
} m({}), bias({});

int n, k;
vector<ll> h, a, b;

void insert(int idx) {
    m.RangeAdd(0, h[idx]-1, -b[idx]);
    m.RangeAdd(h[idx], SZ, a[idx]);
    bias.RangeAdd(0, h[idx]-1, b[idx]*h[idx]);
    bias.RangeAdd(h[idx], SZ, -a[idx]*h[idx]);
}

void pop(int idx) {
    m.RangeAdd(0, h[idx]-1, b[idx]);
    m.RangeAdd(h[idx], SZ, -a[idx]);
    bias.RangeAdd(0, h[idx]-1, -b[idx]*h[idx]);
    bias.RangeAdd(h[idx], SZ, a[idx]*h[idx]);
}

bool check(int idx) {
    return m[idx]<0LL;
}

int optimalHeight() {
    int lo=0,hi=100000,mid;
    if(check(hi)) return hi;
    // else, check(lo) is true, and check(hi) is false.
    while(lo+1<hi) {
        mid=lo+hi>>1;
        if(check(mid)) lo=mid;
        else hi=mid;
    }
    return hi;
}

ll work() {
    int h = optimalHeight();
    // cout << "optimal Height: " << h << "\treturn value: " << m[h]*h+bias[h] << '\n' << "(h,m[h],bias[h])=(" << h << ",\t" << m[h] << ",\t" << bias[h] << ")\n";
    return h*m[h]+bias[h];
}

void init() {
    for(int i=0;i<k;++i) insert(i);
    ans = work();
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    h.resize(n);
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;++i) cin >> h[i];
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) cin >> b[i];

    init();

    for(int i=0;i+k<n;++i) {
        pop(i);
        insert(i+k);
        // cout << "Pop " << i << "\tand Insert " << i+k << '\n';
        ans = min(ans, work());
    }

    cout << ans;

    return 0;
}