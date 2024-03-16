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
            inv_map[b] = a;
            ret = true;
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, n, m; cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        graph[a].insert(b);
    }

    int ans = 0;
    for(a=1;a<=n;++a) {
        visited.clear();
        if(match(a)) ++ans;
    }
    cout << ans;
    
    return 0;
}