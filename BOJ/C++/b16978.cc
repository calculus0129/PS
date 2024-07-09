#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int SIZE=1<<17;

struct Node {
    ll val;
    Node *left, *right;
    Node(ll val = 0) : val(val), left(NULL), right(NULL) {}
    Node(ll val, Node* l, Node* r) : val(val), left(l), right(r) {}
};

class PST {
    public:
    Node *versions[101010];
    int ver;
    PST(const vector<ll> &arr)
    : ver(1) {
        memset(versions, 0, sizeof(versions));
        versions[0] = build(0, SIZE-1, arr);
    }
    void put(int pos, ll newValue) {
        versions[ver] = update(versions[ver-1], pos, newValue, 0, SIZE-1);
        ++ver;
    }
    ll query(int version, int l, int r) {
        return query(versions[version], l, r, 0, SIZE-1);
    }
    private:
    Node* build(int l, int r, const vector<ll> &arr) {
        if(l>=arr.size()) return new Node();
        if(l == r) {
            return new Node(arr[l]);
        }
        int mid = l+r>>1;
        auto leftChild = build(l, mid, arr);
        auto rightChild = build(mid+1, r, arr);
        return new Node(leftChild->val + rightChild->val, leftChild, rightChild);
    }
    Node* update(Node *node, int pos, ll v, int s, int e) {
        Node *ret;
        // if(!node) ret = new Node();
        ret = new Node(0LL, node->left, node->right);
        if(s == e) {
            ret->val = v;
            return ret;
        }
        int mid = s+e>>1;
        if(pos<=mid) ret->left = update(node->left, pos, v, s, mid);
        else ret->right = update(node->right, pos, v, mid+1, e);
        ret->val = (ret->left?ret->left->val:0) + (ret->right ? ret->right->val : 0);
        return ret;
    }
    ll query(Node* node, int ql, int qr, int l, int r) {
        // if(!node) node = new Node();
        if(qr<l || r<ql) return 0LL;
        if(ql<=l && r<=qr) return node->val;
        int mid = l+r>>1;
        return query(node->left, ql, qr, l, mid) + query(node->right, ql, qr, mid+1, r);
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