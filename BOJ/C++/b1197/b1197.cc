#include <bits/stdc++.h>
using namespace std;

class edge {
    public:
        int w, a, b;
};

bool cmp(const edge& a, const edge& b) {
    return a.w>b.w;
}

int main() {
    priority_queue<edge, vector<edge>, bool(*)(const edge&, const edge&)> pq(cmp);
    cin.tie(0)->sync_with_stdio(0);
    int m, n, i, cost = 0, cnt=0, a, b, w;
    cin >> m >> n;
    vector<int> s(m+1); // Represents disjoint sets.
    for(i=0;i<=m;++i) s[i] = i;
    edge tmp, f;
    while(n--) {
        cin >> tmp.a >> tmp.b >> tmp.w;
        pq.push(tmp);
    }
    while(cnt<m-1) {
        f = pq.top(); pq.pop();
        a = f.a, b = f.b;
        while(a!=s[a]) a = s[a];
        while(b!=s[b]) b = s[b];
        if(a == b) continue;
        cost+=f.w; ++cnt;
        s[a] = s[b] = min(a, b);
    }
    cout << cost;

    return 0;
}