#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

vector<int> solve(int a, int b, int k) {
    if(a>b) swap(a, b);
    vector<int> ret(b-a, a);
    k -= b-a;
    bool r = false;
    int c = a;
    while(k-->0) {
        if(r) c--;
        r = !r;
        ret.push_back(c);
    }
    return ret;
}

struct cmp {
    bool operator()(const pair<vector<int>,int> &p1, const pair<vector<int>,int> &p2) {
        if(p1.first.size() == p1.second) return true;
        else if(p2.first.size() == p2.second) return false;
        int mi = min(p1.first.size() - p1.second, p2.first.size() - p2.second);
        for(int i=0;i<mi;++i) if(p1.first[i+p1.second] != p2.first[i+p2.second]) return p1.first[i+p1.second] > p2.first[i+p2.second];
        if(p1.first.size()-p1.second != p2.first.size()-p2.second) return p1.first.size()-p1.second < p2.first.size()-p2.second;
        return true; // This must not HAPPEN!
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int n, k, a, b, mx=0;
        cin >> n >> k;
        priority_queue<pair<vector<int>,int>, vector<pair<vector<int>,int>>, cmp> pq;
        for(int i=0;i<n;++i) {
            cin >> a >> b;
            pq.push({solve(a, b, k), 0});
            mx += a + b;
        }
        int ans = 0;
        if(k<=mx) while(k--) {
            auto [v, idx] = pq.top(); pq.pop();
            ans += v[idx++];
            pq.push({v, idx});
        } else ans = -1;
        cout << ans << '\n';
    }
    return 0;
}