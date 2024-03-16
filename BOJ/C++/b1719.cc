#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
int m;
map<int, vector<pii>> graph;
int dist[201], ans[201];
bool visited[201];
auto cmp = [](pii x, pii y) {
    return x.Y>=y.Y;
};

void work(int n) {
    for(int i=1;i<=m;++i) {
        ans[i] = -1;
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    visited[n] = true;
    dist[n]=0;
    priority_queue<pii, vector<pii>, bool(*)(pii, pii)> pq(cmp);
    for(pii p: graph[n]) if(p.Y<dist[p.X]) {
        pq.push({ans[p.X] = p.X, dist[p.X] = p.Y});
    }
    while(!pq.empty()) {
        if(!visited[pq.top().X]) {
            int x = pq.top().X, y = pq.top().Y; pq.pop();
            visited[x]=true;
            for(pii p: graph[x]) if(!visited[p.X] && y + p.Y<dist[p.X]) {
                pq.push({p.X, dist[p.X] = y + p.Y});
                ans[p.X] = ans[x];
            }
        } else pq.pop();
    }
    for(int i=1;i<=m;++i) {
        if(ans[i]<0) cout << "- ";
        else cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> m >> n;
    int a, b, c;
    while(n--) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for(int i=1;i<=m;++i) {
        work(i);
    }

    return 0;
}