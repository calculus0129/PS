#include <bits/stdc++.h>
using namespace std;

// bipartite matching 1st trial

unordered_map<int, unordered_set<int>> graph;
unordered_map<int, int> inv_map;
unordered_set<int> visited;

bool connectable(int a) {
    bool ret = false;
    for(int b: graph[a]) if(visited.find(b) == visited.end()) {
        visited.insert(b);
        if(inv_map.find(b) == inv_map.end() || connectable(inv_map[b])) {
            ret = true;
            inv_map[b] = a;
            break; // Necessary. Unless this exist, multiple b may refer to the same a.
        }
        //visited.erase(b); // NO!!! This KILLS performance!!!
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=1, a, b;i<=n;++i) {
        cin >> a;
        while(a--) {
            cin >> b;
            graph[i].insert(b);
        }
    }

    int ans = 0;
    for(int a=1;a<=n;++a) {
        visited.clear();
        if(connectable(a)) ++ans;
    }

    cout << ans;

    return 0;
}