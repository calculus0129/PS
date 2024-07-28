#include <bits/stdc++.h>
#define BIG 1000000
#define ABS(a) ((a)<0.0?(0.0):(a))
#define VAL(x) ((x)?(x)->v:T())
using namespace std;
const int SZ = 1<<21;

template<class T>
struct Node {
    T v;
    Node *l, *r;
    Node(T v=T(), Node* l=NULL, Node* r=NULL)
    : v(v), l{l}, r{r} {}
};

template<class T>
struct Seg {
    Node<double> *root;
    Seg() {
        root = new Node<T>();
    }
    // Update by adding
    void update(int pos, T v) {
        update(pos, v, root);
    }
    // Range Sum Query
    T rangeSum(int l, int r) {
        if(r<l) return 0.0;
        return rangeSum(l, r, root);
    }
    // Update by adding
    void update(int pos, T v, Node<T> *node, int s=0, int e=SZ-1) {
        if(s == e) {
            node -> v += v;
            return;
        }
        int mid = s + e >> 1;
        if(pos <= mid) {
            if(!node->l) node->l = new Node<T>();
            update(pos, v, node->l, s, mid);
        } else {
            if(!node->r) node->r = new Node<T>();
            update(pos, v, node->r, mid+1, e);
        }
        node -> v = VAL(node->l) + VAL(node->r);
    }

    // Range Sum Query
    T rangeSum(int l, int r, Node<T> *node, int s=0, int e = SZ-1) {
        if(!node) return 0.0;
        if(r<s || e<l) return 0.0;
        if(l<=s && e<=r) return node->v;
        int mid = s + e >> 1;
        return rangeSum(l, r, node->l, s, mid) + rangeSum(l, r, node->r, mid+1, e);
    }
};

struct CoordSolving {
    Seg<double> sums, cnt;
    int n;
    CoordSolving(const vector<int> &coords, const vector<double> &p)
    : n(coords.size()) {
        // assert(p.size() == n);
        for(int i=0;i<n;++i) {
            sums.update(coords[i]+BIG, (coords[i]+BIG)*p[i]);
            cnt.update(coords[i]+BIG, p[i]);
        }
    }
    double query(int coord) {
        coord += BIG;
        return (cnt.rangeSum(0, coord-1)-cnt.rangeSum(coord+1, BIG<<1))*coord
            -sums.rangeSum(0, coord-1)+sums.rangeSum(coord+1, BIG<<1);
    }
};

void solve() {
    int m, n, xc, yc; cin >> n;
    vector<int> x(n), y(n);
    vector<double> p(n);
    for(int i=0;i<n;++i) cin >> x[i] >> y[i];
    for(int i=0;i<n;++i) cin >> p[i];
    CoordSolving X(x, p), Y(y, p);
    cin >> m;
    while(m--) {
        cin >> xc >> yc;
        cout << X.query(xc) + Y.query(yc) << '\n';
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout << setprecision(8);
    int T, test_case; cin >> T;
    for(test_case=0;test_case<T;++test_case) {
        cout << "Case #" << test_case+1 << '\n';
        // Print the answer
        solve();
    }
    return 0;
}