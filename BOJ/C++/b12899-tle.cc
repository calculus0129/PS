#include <bits/stdc++.h>
using namespace std;
const int SZ = 1<<21;
struct Node {
    int v;
    Node *l, *r;
    Node(int v=0, Node *l=NULL, Node *r=NULL)
    : v(v), l(l), r(r) {}
};
struct Seg {
    Node *root;
    Seg() {
        root = new Node;
    }
    void q1(int x) {
        update(root, 0, SZ-1, x, 1);
    }
    int q2(int x) {
        int lo=0, hi=SZ-1, mid;
        auto check = [x, this](int q) -> bool{
            return this->query(this->root, 0, SZ-1, 0, q) >= x;
        };
        if(check(lo)) hi = lo;
        else while(lo+1<hi) {
            mid = lo + hi >> 1;
            if(check(mid)) hi = mid;
            else lo = mid;
        }
        update(root, 0, SZ-1, hi, -1);
        return hi;
    }

    private:
    void update(Node *node, int s, int e, int pos, int v) {
        node->v += v;
        if(s == e) return;
        int mid = s + e >> 1;
        if(pos<=mid) {
            if(!node->l) node->l = new Node();
            update(node->l, s, mid, pos, v);
        } else {
            if(!node->r) node->r = new Node;
            update(node->r, mid+1, e, pos, v);
        }
    }
    int query(Node *node, int s, int e, int l, int r) {
        if(!node || r<s || e<l) return 0;
        if(l<=s && e<=r) return node->v;
        int mid = s + e >> 1;
        return query(node->l, s, mid, l, r) + query(node->r, mid+1, e, l, r);
    }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    Seg seg;
    int q;
    cin >> q;
    while(q--) {
        int a, x;
        cin >> a >> x;
        if(a == 1) seg.q1(x);
        else cout << seg.q2(x) << '\n';
    }

    return 0;
}