#include <bits/stdc++.h>
using namespace std;
int n, ans;
unordered_map<int, unordered_set<int>> graph;
bool discovered[1001];

void bfs(int src, int tgt) {
    queue<int> q1, q2;
    queue<int> &que=q1, &tmp=q2;
    int t=0, f;
    que.push(src); discovered[src] = true;
    while(!que.empty() && !discovered[tgt]) {
        while(!que.empty()) {
            f = que.front(); que.pop();
            for(int v: graph[f]) if(!discovered[v]) {
                discovered[v] = true;
                tmp.push(v);
            }
        }
        swap(que, tmp);
        ++t;
    }
    if(discovered[tgt]) ans = t;
    else ans = -1;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, m, x, y;
    cin >> a >> b;
    cin >> n >> m;
    while(m--) {
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    bfs(a, b);
    cout << ans;

    return 0;
}