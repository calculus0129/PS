#include <bits/stdc++.h>
using namespace std;
vector<int> graph[201];
int n;
bool visited[201];

void dfs(int node) {
    visited[node] = true;
    for(int next: graph[node]) if(!visited[next]) {
        dfs(next);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for(int i=1, j, a;i<=n;++i) {
        for(j=1;j<=n;++j) {
            cin >> a;
            if(a == 1) graph[i].push_back(j);
        }
    }
    int a;
    cin >> a;
    dfs(a);
    bool r = true;
    for(int i=1;i<m;++i) {
        cin >> a;
        if(!visited[a]) r = false;
    }
    cout << (r?"YES":"NO");
    
    return 0;
}