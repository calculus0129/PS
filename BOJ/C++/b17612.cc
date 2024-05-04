#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int n, k;

struct outInfo {
    int id;
    int counterNo;
    int time;
};

bool cmp0(const pii &a, const pii &b) {
    return a.second == b.second ? a.first > b.first : a.second > b.second;
}

bool cmp1(const outInfo &a, const outInfo &b) {
    return a.time == b.time ? a.counterNo < b.counterNo : a.time > b.time;
}

priority_queue<pii, vector<pii>, bool(*)(const pii &, const pii &)> pq0(cmp0);
priority_queue<outInfo, vector<outInfo>, bool(*)(const outInfo &, const outInfo &)> pq1(cmp1);

void go_in() {
    int id, w, i=0;
    while(i++<n) {
        cin >> id >> w;
        pii p = pq0.top(); pq0.pop();
        pq1.push({id, p.first, p.second + w});
        pq0.push({p.first, p.second + w});
    }
}

void input() {
    cin >> n >> k;
    for(int i=1;i<=k;++i) pq0.push({i, 0});
    go_in();
}

ll answer() {
    ll ret = 0LL, i=0LL;
    while(i++<n) {
        // cout << i << "\t: ";
        // cout << pq1.top().id << ", ";
        // cout << pq1.top().counterNo << ", ";
        // cout << pq1.top().time << ", \n";
        ret += pq1.top().id * i;
        pq1.pop();
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    input();
    cout << answer();
    return 0;
}