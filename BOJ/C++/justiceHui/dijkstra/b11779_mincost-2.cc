#include <bits/stdc++.h>
#define INF (int)1e8+1
struct nodes {
    int cost, node;
    bool operator<(const nodes &n) const {
        return cost > n.cost;
    }
};
using namespace std;
int d[1010], par[1010];
vector<nodes> g[1010];
priority_queue<nodes> pq;

void dijkstra(int start) {
    int cost, node, newcost;
    while(!pq.empty()) {
        cost = pq.top().cost, node = pq.top().node; pq.pop();
        if(cost!=d[node]) continue;
        for(const nodes &i: g[node]) {
            newcost = cost+i.cost;
            if(newcost<d[i.node]) {
                d[i.node] = newcost;
                par[i.node] = node;
                pq.push({newcost, i.node});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, start, end;
    int m, n;
    cin >> m >> n;
    fill(d+1, d+m+1, INF);
    while(n--) {
        cin >> a >> b >> c;
        g[a].push_back({c, b});
    }
    cin >> start >> end;
    d[start]=0;
    par[start] = start;
    pq.push({0, start});
    dijkstra(start);
    vector<int> path(1, end);
    int x = end;
    while(par[x]!=x) path.push_back(x=par[x]);
    cout << d[end] << '\n';
    cout << path.size() << '\n';
    for(auto i = path.rbegin(), e = path.rend();i!=e;++i)
        cout << *i << ' ';

    return 0;
}