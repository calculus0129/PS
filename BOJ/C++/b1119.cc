#include <bits/stdc++.h>
using namespace std;
bool no;
int n;
vector<int> graph[51];
void input() {
    char inp[51];
    for(int i=0, j;i<n;++i) {
        cin >> inp;
        for(j=0;j<n;++j) if(inp[j] == 'Y') graph[i].push_back(j);
    }
}

void e_num_check() {
    // Check if the number of all edges is less than n-1 or not.
    int ret=0;
    for(int i=0;i<n;++i) ret += graph[i].size();
    // By handshaking theorem, ret must be the twice of the number of nodes.
    if((ret>>1)<n-1) no = true;
}

bool visited[51];

// returns the size of the connected component!
int dfs(int node) {
    int ret = 1;
    visited[node]=true;
    for(int next: graph[node]) {
        if(!visited[next]) ret += dfs(next);
    }
    return ret;
}

int cc_num() {
    bool oneExists = false;
    int ret = 0;
    for(int i=0;i<n;++i) if(!visited[i]) {
        if(dfs(i)<2) oneExists = true;
        ++ret;
    }
    if(n > 1 && oneExists) no = true;
    return ret;
}

int main() {
    assert((0>>1) == 0);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    input();
    e_num_check();
    int cnum = cc_num();
    if(no) {
        cout << -1;
    } else {
        cout << cnum-1;
    }
    return 0;
}