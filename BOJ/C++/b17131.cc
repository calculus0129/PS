#include <bits/stdc++.h>
#define X first
#define Y second
#define ALL(x) x.begin(), x.end()
#define MUL(x,y) ((ll)(x) * (y) % P)
#define ADD(x,y) (((x)+(y))%P)
using namespace std;
const int P = 1000000007;
const int SZ = 1<<19;

int segtree[SZ<<1];
void update(int pos, int num) {
    pos += SZ;
    while(pos) {
        segtree[pos] += num;
        pos>>=1;
    }
}

int query(int l, int r) {
    l += SZ, r += SZ;
    int ret=0;
    while(l<=r) {
        if(l&1) ret += segtree[l++];
        if(~r&1) ret += segtree[r--];
        l>>=1; r>>=1;
    }
    return ret;
}

typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> coords(n);
    for(int i=0;i<n;++i) cin >> coords[i].X >> coords[i].Y;
    sort(ALL(coords), [](const pair<int,int> &a, const pair<int,int> &b) -> bool {
        return a.Y > b.Y;
    });
    int y = SZ, ans = 0, prev = 0;
    for(int i=0, j;i<n;++i) {
        if(coords[i].Y<y) {
            for(j=prev;j<i;++j) ans = ADD(ans, MUL(query(0, (SZ>>1)+coords[j].X-1), query((SZ>>1)+coords[j].X+1, SZ-1)));
            for(j=prev;j<i;++j) update((SZ>>1)+coords[j].X, 1);
            prev = i;
            y = coords[i].Y;
        }
    }
    for(int j=prev;j<n;++j) ans = ADD(ans, MUL(query(0, (SZ>>1)+coords[j].X-1), query((SZ>>1)+coords[j].X+1, SZ-1)));
    cout << ans;
    return 0;
}