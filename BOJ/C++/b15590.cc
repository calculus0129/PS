#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m, rn;
struct milk {
    int q, p;
    bool operator<(const milk & other) const {
        return p==other.p?q<other.q:p<other.p;
    }
};
milk milks[101010];
ll q[101010], p[101010], ans;
ll c[101010], r[101010];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> rn;
    for(int i=0;i<n;++i) cin >> c[i];
    for(int i=0;i<m;++i) {
        cin >> milks[i].q >> milks[i].p;
    }
    for(int i=0;i<rn;++i) cin >> r[i];
    sort(c, c+n, greater<ll>());
    sort(milks, milks+m, [](const milk &x, const milk &y) {
        return y<x;
    });
    sort(r, r+rn, greater<ll>());
    for(int i=0;i<m;++i) {
        q[i+1] = q[i] + milks[i].q;
        p[i+1] = p[i] + milks[i].q*milks[i].p;
    }
    // ll * qptr;

    ll total=0LL, prevmilk=0LL, milkincome;
    int idx, j=0;
    for(int i=0;i<n;) {
        idx = upper_bound(q, q+m+1, total+c[i]) - q;
        if(idx > m) {
            milkincome = p[m] - prevmilk;
        }
        else milkincome = p[idx-1] + (total+c[i]-q[idx-1])*milks[idx-1].p - prevmilk;
        if(j < rn && r[j] > milkincome) {
            --n;
            ans += r[j++];
        } else {
            total += c[i++];
            prevmilk += milkincome;
            ans += milkincome;
        }
    }
    cout << ans;

    return 0;
}