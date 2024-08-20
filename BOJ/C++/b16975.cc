#include <bits/stdc++.h>
#define VAL(x) (x?x->v:0LL)
using namespace std;
const int SZ = 1<<17;
typedef long long ll;

struct Node {
    ll v, lz;
    Node *l, *r;
    Node(ll v=0LL, ll lz=0LL, Node *l=NULL, Node *r = NULL)
    : v(v), lz(lz), l(l), r{r} {}
};

struct Seg {
    Node *root;
    Seg(const vector<ll> &arr)
    : root(new Node) {
        for(int i=0,n=arr.size();i<n;++i) {
            update(i, i, arr[i]);
        }
    }
    void update(int l, int r, ll v) {
        update(root, 0, SZ-1, l, r, v);
    }
    ll query(int l, int r) {
        return query(root, 0, SZ-1, l, r);
    }
    private:
    void lazyprop(Node *node, int s, int e) {
        if(node->lz) {
            node->v += node->lz * (e-s+1);
            if(s!=e) {
                if(!node->l) node->l = new Node;
                if(!node->r) node->r = new Node;
                node->l->lz += node->lz;
                node->r->lz += node->lz;
            }
            node->lz=0LL;
        }
    }
    void update(Node *node, int s, int e, int l, int r, ll v) {
        lazyprop(node, s, e);
        if(r<s || e<l) return;
        if(l<=s && e<=r) {
            node->lz = v;
            lazyprop(node, s, e);
            return;
        }
        if(!node->l) node->l = new Node();
        if(!node->r) node->r = new Node();
        int m = s+e>>1;
        update(node->l, s, m, l, r, v);
        update(node->r, m+1, e, l, r, v);
        node->v = node->l->v + node->r->v;
    }
    ll query(Node *node, int s, int e, int l, int r) {
        lazyprop(node, s, e);
        if(!node || r<s || e<l) return 0LL;
        if(l<=s && e<=r) return node->v;
        int m = s+e >> 1;
        return query(node->l, s, m, l, r) + query(node->r, m+1, e, l, r);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    Seg seg(arr);
    int q; cin >> q;
    while(q--) {
        int m, i, j, k; cin >> m;
        if(m == 1) {
            cin >> i >> j >> k;
            seg.update(i-1, j-1, k);
        } else {
            cin >> i;
            cout << seg.query(i-1, i-1) << '\n';
        }
    }

    return 0;
}