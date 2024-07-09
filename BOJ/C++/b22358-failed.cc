#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;

struct Edge {
    int from, to, t;
    bool operator<(const Edge &other) const {
        return from == other.from ? to == other.to? t<other.t: to<other.to : from < other.from;
    }
};

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
unordered_map<int, vi> inv_graph;
set<Edge> edges;
map<int, map<int, int>> graph, gk;
int n, m, k, s, t;

void relax(const Edge &e, map<int, map<int, int>> &gp) {
    if(gp.find(e.from) != gp.end()) for(int i: inv_graph[e.from]) {
        if(gp[i].find(e.to) == gp[i].end() || gp[i][e.to] < gp[i][e.from] + e.t) {
            gp[i][e.to] = gp[i][e.from] + e.t;
        }
    }
}

void init() {
    for(const Edge &e: edges) {
        graph[e.from][e.to] = e.t;
        for(int i: inv_graph[e.from]) {
            if(graph[i].find(e.to) == graph[i].end()) {
                graph[i][e.to] = graph[i][e.from] + e.t;
                inv_graph[i].push_back(e.to);
            } else if(graph[i][e.to] < graph[i][e.from] + e.t) {
                graph[i][e.to] = graph[i][e.from] + e.t;
            }
        }
    }
    gk[s][s]=0;
}

void work() {
    
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> s >> t;
    inv_graph.rehash(n+1);
    // for(int i=1;i<=n;++i) fingraph[i][i]=0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.insert({a, b, c});
        // graph[a].insert({b, c});
        inv_graph[b].push_back(a);
    }
    cout << "success";
    // init();

    return 0;
}