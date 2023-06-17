#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n, m, t[100], ans;
vector<pii> graph[100];

bool cmp(pii x, pii y) {
    return x.second>y.second;
}

void work(int from) {
    vector<int> D(n, 16);
    vector<bool> chk(n, false);
    priority_queue<pii, vector<pii>, bool(*)(pii, pii)> pq(cmp);
    pq.push({from, 0});
    pii tmp;
    int dist, an=0;
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        if(chk[tmp.first]) continue;
        chk[tmp.first] = true;
        dist = D[tmp.first] = tmp.second; // D[tmp.first] = ... may not be so necessary!
        if(dist > m) break;
        an += t[tmp.first];
        for(pii j: graph[tmp.first]) {
            if(D[j.first] > dist + j.second) {
                D[j.first] = dist + j.second;
                pq.push(make_pair(j.first, D[j.first]));
            }
        }
    }
    ans = max(ans, an);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    int r, i, a, b, w;
    cin >> n >> m >> r;
    for(i=0;i<n;++i) cin >> t[i];
    while(r--) {
        cin >> a >> b >> w;
        graph[a-1].push_back({b-1, w});
        graph[b-1].push_back({a-1, w});
    }
    for(i=0;i<n;++i) work(i);
    cout << ans;

    return 0;
}