#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_map<int, int> inv_map;
unordered_set<int> visited;

bool match(int a) {
    bool ret = false;
    for(int b: graph[a]) if(visited.find(b) == visited.end()) {
        visited.insert(b);
        if(inv_map.find(b) == inv_map.end() || match(inv_map[b])) {
            ret = true;
            inv_map[b] = a;
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=1, a, b;i<=n;++i) {
        cin >> a;
        while(a--) {
            cin >> b;
            graph[i].insert(b);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i) {
        visited.clear();
        if(match(i)) ++ans;
    }
    cout << ans;
    return 0;
}