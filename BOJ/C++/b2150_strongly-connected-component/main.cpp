#include <bits/stdc++.h>
using namespace std;
// https://ip99202.github.io/posts/SCC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/#scc-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%B0%BE%EC%9D%84%EA%B9%8C
// trying Tarjan's Algorithm ... later.!
// now, let's try Kosaraju's Algorithm.

vector<vector<int>> graph, rgraph, scc; // graph, rgraph: graph, reverse-edged graph
vector<int> stk;
int v, e, scc_num, visited[10101];

void dfs(int node) {
    visited[node]=1;
    for(auto nxt: graph[node]) if(!visited[nxt]) {
        dfs(nxt);
    }
    stk.push_back(node);
}

void dfs_all() {
    for(int i=1;i<=v;++i) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    memset(visited, 0, sizeof(visited));
}

void rdfs(int node) {
    visited[node] = 1;
    scc[scc_num].push_back(node);
    for(auto nxt: rgraph[node]) if(!visited[nxt]) { // and the nxt is later popped from stack than node......?
        rdfs(nxt);
    }
}

void rdfs_all() {
    int top;
    vector<int> null;
    while(!stk.empty()) {
        top = stk.back(); stk.pop_back();
        if(!visited[top]) {
            scc.push_back(null);
            rdfs(top);
            sort(scc[scc_num].begin(), scc[scc_num].end());
            ++scc_num;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>v>>e;
    graph.resize(v+1);
    rgraph.resize(v+1);
    int a, b;
    while(e--)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    dfs_all();
    rdfs_all();
    sort(scc.begin(), scc.end(), [](vector<int> &lhs, vector<int> &rhs) {
         return lhs[0]<rhs[0];
    });
    cout << scc_num << "\n";
    for(auto s:scc) {
        for(auto i: s) {
            cout << i << " ";
        }
        cout << "-1\n";
    }
    return 0;
}

/*
13 17
1 2
2 3
3 1
9 6
6 8
8 5
5 7
7 6
10 5
1 5
5 13
13 4
4 3
11 13
13 12
12 11
10 11
=> 3
1 2 3 4 5 6 7 8 11 12 13 -1
9 -1
10 -1
*/
