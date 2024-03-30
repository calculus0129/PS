#include <bits/stdc++.h>
using namespace std;
int n, k;
unordered_map<int, unordered_map<int, int>> graph;
typedef pair<int, int> pii;
map<pii, int> dir;
set<int> remain;
size_t dij[300010], ans;
bool on[500010];
typedef pair<int, size_t> pit;
bool cmp(const pit &a, const pit &b) {
    return a.second>b.second;
}
priority_queue<pit, vector<pit>, bool(*)(const pit &, const pit &)> pq(cmp);

void addEdge(int a, int b, int c, int idx) {
    dir[{a, b}]=idx;
    graph[a][b] = c;
    graph[b][a] = (c<<1);
}

void dijkstra() {
    int node, nxt;
    while(!remain.empty()) {
        if(remain.find(node=pq.top().first) == remain.end()) {
            pq.pop();
            continue;
        }
        for(auto i: graph[node]) if(dij[nxt=i.first] > graph[node][i.first] + dij[node]) {
            if(dir.find({node, nxt}) != dir.end()) on[dir[{node, nxt}]] = true;
            dij[nxt] = graph[node][nxt] + dij[node];
            pq.push({nxt, dij[nxt]});
        }
        remain.erase(node);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> n >> k;
    for(int _=0;_<k;++_) {
        cin >> a >> b >> c;
        addEdge(a, b, c, _);
    }
    fill(dij+1, dij+n+1, ULLONG_MAX);
    dij[1] = 0ULL;
    pq.push({1, 0ULL});
    for(int i=1;i<=n;++i) remain.insert(i);
    dijkstra();
    for(int i=1;i<=n;++i) ans += dij[i];
    cout << ans << '\n';
    for(int i=0;i<k;++i) cout << (int) on[i] << ' ';
    
    return 0;
}