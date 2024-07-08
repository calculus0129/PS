#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10101];
int n, match[10101], inv_match[10101], dist[10101];

void input() {
    for(int i=0;i<10101;++i) graph[i].clear();
    for(int i=0;i<n;++i) {
        int a, nb;
        scanf("%d: (%d)", &a, &nb);
        for(int j=0;j<nb;++j) {
            int b;
            scanf("%d", &b);
            graph[a].push_back(b-n);
        }
    }
}

bool bfs() {
    queue<int> q;
    for(int a=0;a<n;++a) {
        if(match[a] == n) {
            dist[a] = 0;
            q.push(a);
        } else {
            dist[a] = INT_MAX;
        }
    }
    dist[n] = INT_MAX;
    while(!q.empty()) {
        int a = q.front(); q.pop();
        if(dist[a] < dist[n]) {
            for(int b: graph[a]) {
                if(dist[inv_match[b]] == INT_MAX) {
                    dist[inv_match[b]] = dist[a] + 1;
                    q.push(inv_match[b]);
                }
            }
        }
    }
    return dist[n] != INT_MAX;
}

bool dfs(int a) {
    if(a!=n) {
        for(int b: graph[a]) {
            if(dist[inv_match[b]] == dist[a] + 1) {
                if(dfs(inv_match[b])) {
                    inv_match[b] = a;
                    match[a] = b;
                    return true;
                }
            }
        }
        dist[a] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    // initialize all to -1: set each byte to 0xFF.
    // memset(match, -1, sizeof(match));
    // memset(inv_match, -1, sizeof(inv_match));
    fill(match, match+n, n);
    fill(inv_match, inv_match+n, n);

    int matching = 0;
    while(bfs()) {
        for(int a=0;a<n;++a) {
            if(match[a] == n && dfs(a)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    while(scanf("%d", &n)>0) {
        input();
        printf("%d\n", hopcroftKarp());
    }
    
    return 0;
}