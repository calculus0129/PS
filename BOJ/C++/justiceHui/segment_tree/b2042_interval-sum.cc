#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll sum(vll const &tree, int start, int end, int node, int l, int r) {
    if(l>=start && r<=end) return tree[node];
    if(l>end || r<start) return 0LL;
    return sum(tree, start, end, node<<1, l, l+r>>1) + sum(tree, start, end, node<<1|1, (l+r>>1)+1, r);
}

// return the tree index of node corresponding to idx [1~(1<<dep)]th value of actual array.
int find(int idx, int depth) {
    return (1<<depth)-1+idx;
}

void change(vll &tree, int idx, ll diff) {
    tree[idx]+=diff;
    // idx th node's parent number is ceil(idx/2).
    while(idx>>=1) tree[idx]+=diff;
}

int main() {
    vll tree; // arr
    int a, b, dep=-1, m, n, i, j, e;
    ll c; // ...!
    cin.tie(0)->sync_with_stdio(0);

    // Just assertions (all passed)
    /*
    vll arr, ans_arr({6, 3, 1});
    i=13;
    while(i>>=1) arr.push_back(i);
    assert(arr.size()==ans_arr.size());
    for(i=0;i<3;++i) assert(arr[i]==ans_arr[i]);
    assert((i<<1)+1==(i<<1|1));
    */

    cin >> n >> b >> c;
    m = b+c;
    while((1<<++dep)<n);

    // Just assertion
    //assert(n>(1<<dep-1) && n<=(1<<dep));

    tree.resize(1<<dep<<1);
    for(i=(1<<dep), e=i+n;i<e;++i) cin >> tree[i];
    
    // init
    for(j=dep-1;j>=0;--j) {
        for(i=(1<<j),e=(i<<1);i<e;++i) tree[i] = tree[i<<1] + tree[i<<1|1];
    }

    while(m--) {
        cin >> a >> b >> c;
        switch(a) {
            case 1: // changing the number.
                b = find(b, dep);
                change(tree, b, (ll)c-tree[b]);
                break;
            case 2: // evaluating the sum.
                cout << sum(tree, b, c, 1, 1, (1<<dep)) << '\n';
                break;
        }
    }


    return 0;
}