#include <bits/stdc++.h>
using namespace std;
int main () {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, p, indeg[501]={}, times[501]={}, t[501];
    vector<int> g[501], rg[501];
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(i=1;i<=n;++i) {
        cin >> t[i];
        cin >> p;
        while(p!=-1) {
            g[p].push_back(i);
            rg[i].push_back(p);
            indeg[i]++;
            cin >> p;
        }
        if(!indeg[i]) {
            pq.push(i);
        }
    }
    while(!pq.empty()) {
        int top = pq.top(); pq.pop();
        for(int i:g[top]) {
            if(!--indeg[i]) pq.push(i);
        }
        for(int i:rg[top]) {
            times[top] = max(times[top], times[i]);
        }
        times[top]+=t[top];
    }
    for(i=1;i<=n;++i) cout << times[i] << '\n';
    return 0;
}