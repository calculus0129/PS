#include <bits/stdc++.h>
using namespace std;
const int SZ = 1<<17;
int segtree[SZ<<1];

void init() {
    for(int i=SZ-1;i;--i) {
        segtree[i] = segtree[i<<1] + segtree[i<<1|1];
    }
}

void update(int pos, int v) {
    pos += SZ;
    while(pos) {
        segtree[pos] += v;
        pos>>=1;
    }
}

int query(int l, int r) {
    int ret = 0;
    while(l<=r) {
        if(l&1) ret += segtree[l++];
        if(~r&1) ret += segtree[r--];
        l>>=1, r>>=1;
    }
    return ret;
}

int index(int idx) {
    int ret = 1, _=17;
    while(_--) {
        ret<<=1;
        if(idx>segtree[ret]) {
            idx -= segtree[ret];
            ret |= 1;
        }
    }
    return ret-SZ;
}

int main() {
    int n, k, len=0;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=0;i<n;++i) segtree[i|SZ]=1;
    init();
    vector<int> ans(n), add;
    for(int idx=(k-1)%n+1,_=n;_;--_) {
        add.push_back(index(idx));
        // cout << "add index(" << idx << "): " << index(idx) << '\n';
        idx += k;
        if(idx>n) {
            idx = (idx-n-1) % max(1UL, n-add.size())+1;
            n -= add.size();
            // cout << "flush\n";
            for(int i: add) {
                update(i, -1);
                ans[len++] = i+1;
            }
            add.clear();
        }
    }
    cout << '<' << ans[0];
    for(int i=1,e=ans.size();i<e;++i) cout << ", " << ans[i];
    cout << '>';

    return 0;
}