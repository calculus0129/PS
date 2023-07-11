#include <bits/stdc++.h>
using namespace std;
const size_t SIZE = 1<<18;
int segtree[SIZE<<1];

int sum(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    if(l<=start && end<=r) return segtree[node];
    if(end < l || start > r) return 0;
    return sum(l, r, start, start+end>>1, node<<1) + sum(l, r, (start+end>>1)+1, end, node<<1|1);
}

void update(int idx, int v) {
    int node = idx+SIZE, dif = v-segtree[node];
    if(dif) do {
        segtree[node]+=dif;
    } while(node>>=1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int a, arr[SIZE];
    size_t ans;
    unordered_map<int, int> mp;
    
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0;i<n;++i) {
        cin >> a;
        mp[a] = i;
    }

    for(int i=0;i<n;++i) {
        a = mp[arr[i]];
        ans += sum(a, n-1);
        update(a, 1);
    }
    cout << ans;

    return 0;
}