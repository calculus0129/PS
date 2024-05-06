#include <bits/stdc++.h>
using namespace std;

int n, e;
int dTime[100001], lTime[100001]; // 0: undiscovered, 1: discovered, 2: finished
typedef pair<int, int> pii;

struct edge {
    int from, to;
    bool visited, isback;
    // bool operator<(const edge & other) const {
    //     return from == other.from ? to < other.to : from < other.from;
    // }
};

// struct custom_hash {
//     size_t operator() (const edge& x) const {
//         size_t h1 = hash<int>{}(x.from);
//         size_t h2 = hash<int>{}(x.to);
//         return (h1 ^ h2 << 1)<<2 | x.visited << 1 | x.isback;
//     }
// };

bool cmp(const pii &a, const pii &b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

vector<vector<edge>> graph;
set<pii, bool(*)(const pii &, const pii &)> bridges (cmp);

void addEdge(int a, int b) {
    graph[a].push_back({a, b, false, false});
    graph[b].push_back({b, a, false, false});
}

int dfs(int node, int timer=0, int par=0) {
    int ut = dTime[node] = ++timer;
    for(edge &e: graph[node]) if(!e.visited && e.to != par) {
        e.visited = true;
        if(dTime[e.to] == 0) {
            timer = dfs(e.to, timer, node);
            ut = min(ut, lTime[e.to]);
        }
        else {
            e.isback = true;
            // cout << e.from << " to " << e.to << " is back edge!\n";
            ut = min(ut, dTime[e.to]);
        }
    }
    lTime[node] = ut;
    return ++timer;
}

void dfs_traversal() {
    int timer = 0;
    for(int i=1;i<=n && timer<2*n;++i) if(dTime[i] == 0) {
        timer = dfs(i, timer);
    }
    // for(edge e: graph[1]) {
    //     if(e.visited) cout << "visited!";
    // }
}

void find_bridges() {
    for(int i=1, a, b;i<=n;++i) {
        for(edge e: graph[i]) if(e.visited && !e.isback && dTime[e.from]<lTime[e.to]) {
            a = min(e.from, e.to), b = max(e.from, e.to);
            bridges.insert({a, b});
        }
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> e;
    graph.resize(n+1);
    for(int i=0, a, b;i<e;++i) {
        cin >> a >> b;
        addEdge(a, b);
    }
    dfs_traversal();
    find_bridges();
    cout << bridges.size() << '\n';
    for(pii p: bridges) {
        cout << p.first << ' ' << p.second << '\n';
    }
    
    return 0;
}