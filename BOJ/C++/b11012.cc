#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(a) a.begin()
#define END(a) a.end()
#define ALL(a) BEGIN(a), END(a)
using namespace std;
typedef long long ll;
struct Seg2DSweep {
    struct Query {
        bool isPoint, isAdd;
        int x, s, e;
        bool operator<(const Query &q) const {
            return x==q.x ? isPoint < q.isPoint : x < q.x;
        }
    };
    const int SZ;
    vector<int> cseg;
    vector<Query> queries;
    Seg2DSweep(int n=17) : SZ(1<<n) {
        cseg.resize(SZ<<1);
        queries.clear(); // Essential!!!
    }
    void addRect(int x1, int x2, int y1, int y2) {
        queries.push_back({false, true, x1, y1, y2});
        queries.push_back({false, false, x2+1, y1, y2});
    }
    void addPoint(int x, int y) {
        queries.push_back({true, false, x, y, y});
    }
    void handleRect(int s, int e, int node, pair<int,int> q, int val) {
        if(q.Y<s || e<q.X) return;
        if(q.X<=s && e<=q.Y) {
            cseg[node] += val;
        } else {
            int mid = s+e>>1;
            handleRect(s, mid, node<<1, q, val);
            handleRect(mid+1, e, node<<1|1, q, val);
        }
    }
    int handlePoint(int y) {
        y+=SZ;
        int ret = 0;
        while(y) {
            ret += cseg[y];
            y >>= 1;
        }
        return ret;
    }
    ll solve() {
        ll ret = 0LL;
        sort(ALL(queries));
        for(const Query &q: queries) {
            if(q.isPoint) {
                ret += handlePoint(q.s);
            } else {
                handleRect(0, SZ-1, 1, {q.s, q.e}, q.isAdd?1:-1);
            }
        }
        return ret;
    }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        Seg2DSweep sweep;
        int n, m; cin >> n >> m;
        int x1, x2, y1, y2;
        while(n--) {
            cin >> x1 >> y1;
            sweep.addPoint(x1, y1);
        }
        while(m--) {
            cin >> x1 >> x2 >> y1 >> y2;
            sweep.addRect(x1, x2, y1, y2);
        }
        cout << sweep.solve() << '\n';
    }
    return 0;
}