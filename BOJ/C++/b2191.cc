#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> graph;
unordered_map<int, int> inv_map;
unordered_set<int> visited;

bool bip_matching(int a) {
    bool ret = false;
    for(int b: graph[a]) if(visited.find(b) == visited.end()) {
        visited.insert(b);
        if(inv_map.find(b) == inv_map.end() || bip_matching(inv_map[b])) {
            inv_map[b] = a;
            ret = true;
            break;
        }
    }
    return ret;
}

struct pos {
    double x, y;
    double dist(const pos &other) {
        return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
    }
};

pos jee[101], gumong[101];

void make_graph(int n, int m, int dist) {
    for(int i=1, j;i<=n;++i) for(j=1;j<=m;++j) if(jee[i].dist(gumong[j])<=dist) graph[i].insert(j);
}

int main() {
    int n, m, s, v;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> v;
    double x, y;
    for(int i=1;i<=n;++i) {
        cin >> x >> y;
        jee[i] = {x, y};
    }
    for(int j=1;j<=m;++j) {
        cin >> x >> y;
        gumong[j] = {x, y};
    }
    
    make_graph(n, m, s * v);

    int surviv = 0;
    for(int a=1;a<=n;++a) if(bip_matching(a)) {
        ++surviv;
        visited.clear();
    }

    cout << n - surviv;

    return 0;
}