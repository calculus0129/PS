#include <bits/stdc++.h>
using namespace std;
vector<int> g[32001];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int a, b, indeg[32010]={};
    while(n--) {
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }
    for(int i=1;i<=m;++i) if(indeg[i]==0) pq.push(i);
    while(!pq.empty()) {
        int top = pq.top(); pq.pop();
        cout << top << ' ';
        for(auto i: g[top]) {
            indeg[i]--;
            if(!indeg[i]) pq.push(i);
        }
    }
    return 0;
}