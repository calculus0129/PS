#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    int state; // 0: unexplorered, 1: discovered, 2: finished
};

struct edge {
    node* from;
    node* to;
    int state; // 0: unexplorered, 1: discovery, 2: back, 3: forward/cross(although not covered)
};

unordered_map<int, node*> nodemap;
unordered_map<node*, vector<edge>> graph;
int n;

bool dfs_cycle_existence(node* nod) {
    nod->state = 1; // label nod DISCOVERED

    for(edge& e: graph[nod]) if(e.state == 0) {
        switch(e.to->state) {
            case 0: // DISCOVERY edge
                e.state = 1;
                if(dfs_cycle_existence(e.to)) return true;
                break;
            case 1: // BACK edge
                e.state = 2; 
                return true;
                break;
            case 2: // FORWARD or CROSS edge. Tedious and unnecessary to differentiate the two in this case.
                e.state = 3;
        }
    }
    nod -> state = 2; // label nod FINISHED
    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;++i) nodemap[i] = new node({i, 0});

    for(int i=1, m, j, a;i<=n-1;++i) {
        cin >> m;
        graph[nodemap[i]].resize(m);
        for(j=0;j<m;++j) {
            cin >> a;
            graph[nodemap[i]][j].from = nodemap[i];
            graph[nodemap[i]][j].to = nodemap[a];
            graph[nodemap[i]][j].state = 0;
        }
    }
    
    cout << (dfs_cycle_existence(nodemap[1])?"CYCLE":"NO CYCLE");
    return 0;
}