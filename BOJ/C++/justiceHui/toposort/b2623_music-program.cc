#include <bits/stdc++.h>
using namespace std;
vector<int> g[1001], tsort;
int visited[1001], isdfsing[1001], no;

void dfs(int node) {
    visited[node]=isdfsing[node]=1;
    for(auto i: g[node]) {
        if(!visited[i]) dfs(i);
        if(isdfsing[i]) no=1;
        if(no) return;
    }
    tsort.push_back(node);
    isdfsing[node]=0;
}

int main() {
    int m, n, l, i, a, b;
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    while(n--) {
        cin >> l;
        if(l>0) {
            cin >> a;
            while(--l) {
                cin >> b;
                g[b].push_back(a);
                a=b;
            }
        }
    }
    for(i=1;i<=m;++i) if(!no && !visited[i]) dfs(i);
    if(no) cout << 0;
    else for(auto i : tsort) cout << i << '\n';
    return 0;
}