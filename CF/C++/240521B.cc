#include <bits/stdc++.h>
using namespace std;
int n, m, d, dist[101010];

int cookie() {
    int ret = 0;
    for(int i=0;i<=m;++i) {
        ret += (dist[i]-1)/d;
    }
    ret += m+1;
    if(dist[0] == 0) --ret;
    return ret;
}

int decrease(int idx) {
    if(idx == 0 && dist[idx]==0) {
        return 0;
    } else {
        return (dist[idx]-1)/d+(dist[idx+1]-1)/d+1-(dist[idx]+dist[idx+1]-1)/d;
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // cout << (-1)/4 << '\n'; // 0
    int t, a, s, a1, a2;
    cin >> t;
    while(t--) {
        cin >> n >> m >> d;
        for(int i=0, a0=1;i<m;++i,a0=a) {
            cin >> a;
            dist[i] = a-a0;
        }
        dist[m] = n+1-a;
        s=cookie();
        // cout << "cookie: " << s << '\n';
        a1=a2=0;
        for(int i=0, tmp;i<m;++i) {
            tmp = decrease(i);
            if(a1<tmp) {
                a1=tmp;
                a2=1;
            } else if(a1 == tmp) {
                ++a2;
            }
        }
        cout << s-a1 << ' ' << a2 << '\n';
    }
    return 0;
}