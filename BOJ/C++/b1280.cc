#include <bits/stdc++.h>
#define P 1000000007LL
#define ADD(x,y) (((x)+(y))%P)
#define MUL(x,y) (((x)*(y))%P)
#define VAL(x) ((x)?(x)->v:0)
using namespace std;
int n;
const int SZ = 1<<18;
typedef long long ll;

struct Node {
    ll v;
    Node *l, *r;
    Node(ll v=0LL, Node* l=NULL, Node* r=NULL)
    : v(v), l{l}, r{r} {}
};

struct Seg {
    Node *root;
    Seg() {
        root = new Node();
    }
    // Update by adding
    void update(int pos, ll v) {
        update(pos, v, root);
    }
    // Range Sum Query
    ll rangeSum(int l, int r) {
        if(r<l) return 0LL;
        return rangeSum(l, r, root);
    }
    // Update by adding
    void update(int pos, ll v, Node *node, int s=0, int e=SZ-1) {
        if(s == e) {
            node -> v += v;
            return;
        }
        int mid = s + e >> 1;
        if(pos <= mid) {
            if(!node->l) node->l = new Node();
            update(pos, v, node->l, s, mid);
        } else {
            if(!node->r) node->r = new Node();
            update(pos, v, node->r, mid+1, e);
        }
        node -> v = VAL(node->l) + VAL(node->r);
    }

    // Range Sum Query
    ll rangeSum(int l, int r, Node *node, int s=0, int e = SZ-1) {
        if(!node) return 0LL;
        if(r<s || e<l) return 0LL;
        if(l<=s && e<=r) return node->v;
        int mid = s + e >> 1;
        return rangeSum(l, r, node->l, s, mid) + rangeSum(l, r, node->r, mid+1, e);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int coord; cin >> coord;
    Seg sums, cnt;
    sums.update(coord, coord);
    cnt.update(coord, 1LL);
    ll ans = 1LL;
    for(int i=2;i<=n;++i) {
        cin >> coord;
        ans = MUL(ans,
        ((cnt.rangeSum(0, coord-1)-cnt.rangeSum(coord+1, 200000))*coord-sums.rangeSum(0, coord-1)+sums.rangeSum(coord+1, 200000))%P);
        sums.update(coord, coord);
        cnt.update(coord, 1LL);
    }
    cout << ans;

    return 0;
}