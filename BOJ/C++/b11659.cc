#include <bits/stdc++.h>
using namespace std;

int n, m;

class BIT {
public:
    vector<int> T; // tree
    int S; // size
    BIT(int n): S(n), T(n+1) {}
    void update(int p, int v) {
        while(p<=S) {
            T[p] += v;
            p += p&-p;
        }
    }
    // From the array with index 1 to p.
    int sum(int p) {
        int ret = 0;
        while(p>0) {
            ret += T[p];
            p -= p&-p;
        }
        return ret;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    BIT bit(n);
    for(int i=1, a;i<=n;++i) {
        cin >> a; bit.update(i, a);
    }
    while(m--) {
        int a, b; cin >> a >> b;
        cout << bit.sum(b)-bit.sum(a-1) << '\n';
    }
    return 0;
}