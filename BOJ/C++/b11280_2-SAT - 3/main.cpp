#include <bits/stdc++.h>
using namespace std;
int n, scc_num;

vector<vector<int>> graph, rgraph;//, sccs;
vector<int> stk;
int visited[20101];

void dfs(int node) {
    visited[node] = 1;
    for(auto nxt:graph[node]) if(!visited[nxt]) {
        dfs(nxt);
    }
    stk.push_back(node);
}

void dfs_all() {
    for(int i=1, e=((n<<1)|1);i<e;++i) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void rdfs(int node) {
    //sccs[scc_num].push_back(node);
    visited[node] = scc_num;
    for(auto nxt:rgraph[node]) if(!visited[nxt]) {
        rdfs(nxt);
    }
}

void rdfs_all() {
    int top;
    //vector<int> tmp;
    while(!stk.empty()) {
        top = stk.back(); stk.pop_back();
        if(!visited[top]) {
            //sccs.push_back(tmp);
            scc_num++;
            rdfs(top);
        }
    }
}

int main()
{
    int m;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;

    graph.resize((n+1)<<1);
    rgraph.resize((n+1)<<1);
    int a, b, e = ((n<<1)|1);
    while(m--) {
        cin >> a >> b;
        if(a<0) {
            a = -a;
        }
        else {
            a = e-a;
        }
        if(b<0)
        {
            b = b+e;
        }
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }

    dfs_all();
    assert(visited[e-1]==1);
    memset(visited, 0, sizeof(visited));
    //memset(visited, 1, sizeof(visited)); // Process returned 16843009 (0x1010101)
    //return visited[23];
    //assert(visited[23]==-1); // assertion failed!
    rdfs_all();
    for(int i=1;i<=n;++i) {
        if(visited[i] == visited[e-i])
        {
            cout << 0;
            return 0;
        }
    }
    /// unfinished!
    cout << 1;
    return 0;
}
/*
13 20
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
10 -1
9 10
-1 10
=> 1

13 17
-1 2
-2 3
-3 1
-9 6
-6 8
-8 5
-5 7
-7 6
-10 5
-1 5
-5 13
-13 4
-4 3
-11 13
-13 12
-12 11
-10 11
=>1
*/
