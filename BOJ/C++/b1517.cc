#include <bits/stdc++.h>
#define VAL(x) (x?x->v:0)
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
const int SZ = 1<<19;
using namespace std;
vector<int> arr, srr, coords;
typedef long long ll;

struct Node {
    int v;
    Node *l, *r;
    Node(int v=0,Node *l=NULL, Node *r=NULL) :v(v), l{l}, r(r) {}
};

struct Seg {
    Node *root;
    Seg()
    : root(new Node) {}
    void update(int pos) {
        Node *tgt = root;
        int l = 0, u = SZ-1, mid;
        tgt->v++;
        while(l<u) {
            mid = l+u>>1;
            if(pos<=mid) {
                u = mid;
                if(!tgt->l) tgt->l = new Node();
                tgt = tgt->l;
            }
            else {
                l = mid+1;
                if(!tgt->r) tgt->r = new Node();
                tgt = tgt->r;
            }
            tgt->v++;
        }
    }
    int sum(int l, int r) {
        return sum(root, l, r);
    }
    int sum(Node *node, int l, int r, int start=0, int end=SZ-1) {
        if(r<start || end<l) return 0;
        if(l<=start && end <= r) return VAL(node);
        int mid = start + end >> 1;
        if(!node->l) node->l = new Node();
        if(!node->r) node->r = new Node();
        return sum(node->l, l, r, start, mid) + sum(node->r, l, r, mid+1, end);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    srr = arr;
    sort(ALL(srr));
    coords = srr;
    coords.erase(unique(ALL(coords)), END(coords));
    int m = coords.size();
    vector<priority_queue<int>> pqs(m);
    for(int i=0;i<n;++i) pqs[lower_bound(ALL(coords), arr[i]) - BEGIN(coords)].push(i);
    Seg seg;
    ll ans = 0LL;
    for(int i=n-1, idx, coord;~i;--i) {
        coord = lower_bound(ALL(coords), srr[i]) - BEGIN(coords);
        idx = pqs[coord].top(); pqs[coord].pop();
        ans += i-(idx-seg.sum(0, idx-1));
        seg.update(idx);
    }
    cout << ans;

    return 0;
}