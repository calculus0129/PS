#include <bits/stdc++.h>
#define VAL(x) (x?x->v:iden)
const int SZ = 1<<17;
using namespace std;
using F = int(*)(int,int);

struct Node {
    int v;
    Node *l, *r;
    Node(int v=0, Node *l = NULL, Node *r = NULL)
    : v{v}, l{l}, r{r} {}
};

struct Seg {
    Node *root;
    const F fn;
    const int iden;
    Seg(F fn, int iden)
    : root(new Node(iden)), fn(fn), iden{iden} {}
    void upd0(int pos, int v) {
        update(root, 0, SZ-1, pos, v);
    }
    void update(int l, int r) {
        int vl = query(l, l), vr = query(r, r);
        update(root, 0, SZ-1, l, vr);
        update(root, 0, SZ-1, r, vl);
    }
    int query(int l, int r) {
        return query(root, 0, SZ-1, l, r);
    }
    private:
    void update(Node *node, int s, int e, int pos, int v) {
        if(s == e) {
            node->v = v; return;
        }
        int m = s + e >> 1;
        Node *&l = node->l, *&r = node->r;
        if(pos<=m) {
            if(!l) l = new Node(iden);
            update(l, s, m, pos, v);
        } else {
            if(!r) r = new Node(iden);
            update(r, m+1, e, pos, v);
        }
        node->v = fn(VAL(l), VAL(r));
    }
    int query(Node *node, int s, int e, int l, int r) {
        if(!node || r<s || e<l) return iden;
        if(l<=s && e<=r) return VAL(node);
        int m = s + e >> 1;
        return fn(query(node->l, s, m, l, r), query(node->r, m+1, e, l, r));
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        Seg minSeg([](int a, int b)->int{return min(a, b);}, SZ), maxSeg([](int a, int b)->int{return max(a, b);}, 0);
        int n, q;
        cin >> n >> q;
        for(int i=0;i<n;++i) {
            minSeg.upd0(i, i);
            maxSeg.upd0(i, i);
        }
        while(q--) {
            int m, a, b;
            cin >> m >> a >> b;
            if(m) {
                cout << (minSeg.query(a, b) == a && maxSeg.query(a, b) == b?"YES":"NO") << '\n';
            } else {
                minSeg.update(a, b);
                maxSeg.update(a, b);
            }
        }
    }
    return 0;
}