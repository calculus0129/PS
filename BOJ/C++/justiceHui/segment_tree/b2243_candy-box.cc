#include <bits/stdc++.h>
using namespace std;
const size_t dep=20;
const size_t SIZE=1<<dep;
int segtree[SIZE<<1];

void update_plus(int b, int c) {
    int node = SIZE+b;
    if(c!=0) do segtree[node]+=c;
    while (node>>=1);
}

int search_pop(int x) {
    int node=1, nxt, depth=0;
    while(++depth<=dep) {
        nxt=node<<1;
        if(segtree[nxt]<x) {
            x-=segtree[nxt];
            node = nxt|1;
        } else node = nxt;
    }
    int idx = node - SIZE;
    update_plus(idx, -1);
    return idx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b, c;
    cin >> n;
    while(n--) {
        cin >> a;
        if(a==1) {
            cin >> b;
            cout << search_pop(b) << '\n';
        } else {
            cin >> b >> c;
            update_plus(b, c);
        }
    }
    return 0;
}