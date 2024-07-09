#include <bits/stdc++.h>
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define IDX(x) lower_bound(ALL(coords), (x)) - BEGIN(coords)
#define ALL(x) BEGIN(x), END(x)
#define VAL(x) ((x)?(x)->v:0)
using namespace std;
const int SZ = 1<<17;

struct PST {
    struct Node {
        int v;
        Node *l, *r;
        Node(int v=0, Node *l=NULL, Node *r=NULL) : v(v), l(l), r(r) {}
    };
    vector<Node*> versions;
    Node* build(int s, int e) {
        if(s == e) return new Node;
        int mid = s+e>>1;
        Node *left = build(s, mid);
        Node *right = build(mid+1, e);
        int v = left->v + right->v;
        return new Node(v, left, right);
    }
    PST() {
        versions.push_back(build(0, SZ-1));
    }
    void add(int pos) {
        versions.push_back(add(versions.back(), pos, 0, SZ-1));
    }
    int query(int i, int j, int k) {
        return kth(versions[i-1], versions[j], k, 0, SZ-1);
    }
    // add 1 to the corresponding pos th leaf node.
    Node* add(Node* node, int pos, int s, int e) {
        if(s == e) {
            return new Node(node->v + 1);
        }
        Node *ret = new Node(0, node->l, node->r);
        int mid = s+e>>1;
        if(pos<=mid) {
            ret->l = add(node->l, pos, s, mid);
        } else {
            ret -> r = add(node->r, pos, mid+1, e);
        }
        ret->v = ret->l->v + ret -> r->v;
        return ret;
    }
    // Considering each value 1 of the leaf node as each index, the kth smallest index of leaf nodes.
    int kth(Node *prev, Node *now, int k, int s=0, int e=SZ-1) {
        if(s == e) return s;
        int ldif = now->l->v - prev->l->v, mid = s + e >> 1;
        if(k<=ldif) return kth(prev->l, now->l, k, s, mid);
        else return kth(prev->r, now->r, k-ldif, mid+1, e);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> arr(n), coords(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    coords = arr; sort(ALL(coords)); coords.erase(unique(ALL(coords)), END(coords));
    PST p;
    for(int i=0;i<n;++i) p.add(IDX(arr[i]));
    while(q--) {
        int i,j,k; cin >> i >> j >> k;
        cout << coords[p.query(i, j, k)] << '\n';
    }

    return 0;
}