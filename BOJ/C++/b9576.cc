#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool cmp(const pii a, const pii b) {
    return (a.second == b.second)?a.first>b.first:a.second>b.second;
}

set<int> matched;

priority_queue<pii, vector<pii>, bool(*)(const pii, const pii)> pq(cmp);

bool match(pii p) {
    bool ret = false;
    for(int i=p.first;i<=p.second;++i) if(matched.find(i) == matched.end()) {
        matched.insert(i);
        ret = true;
        break;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    int t, m, n;
    cin >> t;
    while(t--) {
        // pq = priority_queue<pii, vector<pii>, bool(*)(const pii, const pii)>(cmp);
        matched.clear();
        cin >> n >> m;
        for(int i=1, a, b;i<=m;++i) {
            cin >> a >> b;
            pq.push({a, b});
        }
        int ans = 0;
        while(m--) {
            if(match(pq.top())) ++ans;
            pq.pop();
        }
        cout << ans << '\n';
    }

    return 0;
}