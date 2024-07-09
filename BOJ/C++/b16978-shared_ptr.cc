#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1<<17;

struct Node {
    ll val;
    shared_ptr<Node> l, r;
    Node(ll val = 0) : val(val), l(nullptr), r(nullptr) {}
    Node(ll val, shared_ptr<Node> l, shared_ptr<Node> r) : val(val), l(l), r(r) {}
};

typedef shared_ptr<Node> sptr;

class PST {
    public:
    vector<sptr> versions;
    PST(const vector<ll> &arr)
    {
        versions.push_back(build(0, SIZE-1, arr));
    }
    void put(int pos, ll newValue) {
        versions.push_back(update(versions.back(), pos, newValue, 0, SIZE-1));
    }
    ll query(int version, int l, int r) {
        return query(versions[version], l, r, 0, SIZE-1);
    }
    private:
    sptr build(int l, int r, const vector<ll> &arr) {
        if(l>=arr.size()) return make_shared<Node>();
        if(l == r) {
            return make_shared<Node>(arr[l]);
        }
        int mid = l+r>>1;
        sptr leftChild = build(l, mid, arr), rightChild = build(mid+1, r, arr);
        return make_shared<Node>(leftChild->val + rightChild->val, leftChild, rightChild);
    }
    sptr update(sptr node, int pos, ll v, int s, int e) {
        // Node *ret;
        // if(!node) ret = new Node();
        sptr ret = make_shared<Node>(0LL, node->l, node->r);
        if(s == e) {
            ret->val = v;
            return ret;
        }
        int mid = s+e>>1;
        if(pos<=mid) ret->l = update(node->l, pos, v, s, mid);
        else ret->r = update(node->r, pos, v, mid+1, e);
        ret->val = (ret->l?ret->l->val:0) + (ret->r ? ret->r->val : 0);
        return ret;
    }
    ll query(sptr node, int ql, int qr, int l, int r) {
        // if(!node) node = new Node();
        if(qr<l || r<ql) return 0LL;
        if(ql<=l && r<=qr) return node->val;
        int mid = l+r>>1;
        return query(node->l, ql, qr, l, mid) + query(node->r, ql, qr, mid+1, r);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];

    PST pst(arr);
    int m, q, ver, a, b; cin >> m;
    ll val;
    while(m--) {
        cin >> q;
        switch(q) {
            case 1:
                cin >> a >> val;
                pst.put(a-1, val);
                break;
            case 2:
                cin >> ver >> a >> b;
                cout << pst.query(ver, a-1, b-1) << '\n';
        }
    }

    return 0;
}