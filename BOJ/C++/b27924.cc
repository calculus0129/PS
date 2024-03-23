#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
map<int, int> unidist, phedist, daldist;
map<int, vector<int>> graph;

void dfs(int node, map<int, int> &mp, int par=0, int dist=0) {
    bool isLeaf = true;
    for(int nxt: graph[node]) if(nxt!=par) {
        isLeaf=false;
        dfs(nxt, mp, node, dist+1);
    }
    if(isLeaf) {
        mp[node] = dist;
    }
}

bool compare() {
    for(const auto &[key, value]: unidist) { // https://stackoverflow.com/questions/1443793/iterate-keys-in-a-c-map
        if(value < phedist[key] && value < daldist[key]) return true;
    }
    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    int i=0;
    while(++i<n) {
        cin >> a >> b;
        if(graph.find(a) == graph.end()) {
            graph[a] = vector<int>();
        }
        if(graph.find(b) == graph.end()) {
            graph[b] = vector<int>();
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> a >> b >> c;
    if(graph[a].size() > 1) {
        dfs(a, unidist);
        dfs(b, phedist);
        dfs(c, daldist);
    }
    cout << (graph[a].size() == 1 || compare() ? "YES" : "NO"); // If UNI is located at the leaf node, he can immediately run away!

    return 0;
}