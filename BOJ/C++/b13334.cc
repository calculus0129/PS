#include <bits/stdc++.h>
using namespace std;
int n;
typedef pair<int, int> pii;

bool cmp0(const pii &a, const pii &b) {
    return a.second-a.first < b.second-b.first;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    priority_queue<pii, vector<pii>, bool(*)(const pii &,const pii &)> pq0(cmp0);
    for(int i=0, a, b;i<n;++i) {
        cin >> a >> b;
        pq0.push({min(a, b), max(a, b)});
    }
    int d;
    cin >> d;
    while(!pq0.empty() && pq0.top().second - pq0.top().first > d) pq0.pop();
    
    map<int, int> imos;
    int s, e;
    while(!pq0.empty()) {
        pii tmp = pq0.top(); pq0.pop();
        s = tmp.first, e = tmp.second;
        imos[e-d]++;
        imos[s+1]--;
    }
    int ans = 0, sum=0;
    for(pii p: imos) {
        sum += p.second;
        if(ans < sum) ans = sum;
    }
    cout << ans;

    return 0;
}