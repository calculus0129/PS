#include <bits/stdc++.h>
using namespace std;
int k, n;
map<int, set<int>> graph;

void addEdge(int a, int b) {
    graph[a].insert(b);
    graph[b].insert(a);
}

int arr[63];

bool check(int node, int step) {
    bool r = true;
    const set<int> &tmp = graph[node];
    for(int i=0;i<step && r;++i) if(tmp.find(arr[i]) == tmp.end()) r = false;
    return r;
}

bool dfs(int node, int step) {
    arr[step++]=node;
    if(step == k) return true;
    bool ret = false;
    for(int next: graph[node]) if(check(next, step)) {
        ret = dfs(next, step);
        if(ret) break;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int f;
    cin >> k >> n >> f;
    for(int i=0, a, b;i<f;++i) {
        cin >> a >> b;
        addEdge(a, b);
    }
    bool exists = false;
    for(int i=1;i<=n && !exists;++i) {
        exists = dfs(i, 0);
    }
    if(exists) {
        for(int i=0;i<k;++i) cout << arr[i] << '\n';
    } else {
        cout << -1;
    }

    return 0;
}