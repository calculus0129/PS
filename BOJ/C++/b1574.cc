#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_map<int, int> inv_map;
unordered_set<int> discovered;

bool connectable(int a) {
    bool ret = false;
    for(int b: graph[a]) if(discovered.find(b) == discovered.end()) {
        discovered.insert(b);
        if(inv_map.find(b) == inv_map.end() || connectable(inv_map[b])) {
            ret = true;
            inv_map[b]=a;
            break;
        }
        // We do not need to do discovered.erase(b); here
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, r, c, n;
    cin >> r >> c >> n;
    for(int i=0, j;i<r;++i) {
        for(j=0;j<c;++j) {
            graph[i].insert(j);
        }
    }
    while(n--) {
        cin >> a >> b;
        graph[a-1].erase(b-1);
    }
    int ans=0;

    for(int i=0;i<r;++i) {
        discovered.clear();
        if(connectable(i)) ++ans;
    }

    cout << ans;
    return 0;
}