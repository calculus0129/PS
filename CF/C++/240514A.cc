// https://codeforces.com/group/7e82Xe5TPn/contest/522836/problem/A

#include <bits/stdc++.h>
using namespace std;
int n;
int state[100]; // ONLY 0: UNDISCOVERED, 1: DISCOVERED, 2: VISITED. (need to track the 'back-edges'!)
vector<vector<int>> graph;

void output(const int arr[]) {
    int brr[100], crr[100], lb=0, lc=0;

    for(int i=0;i<n;++i) {
        if(state[i]) crr[lc++]=arr[i];
        else brr[lb++]=arr[i];
    }
    cout << lb << ' ' << lc << '\n';
    for(int i=0;i<lb;++i) cout << brr[i] << ' ';
    cout << '\n';
    for(int i=0;i<lc;++i) cout << crr[i] << ' ';
    cout << '\n';
}

void make_graph(const int arr[]) {
    graph.clear();
    graph.resize(n);
    for(int i=0, j;i<n;++i) {
        for(j=0;j<n;++j) {
            if(i!=j && arr[j] % arr[i] == 0) {
                graph[i].push_back(j);
            }
        }
    }
}

int dfs(int node) {
    state[node]=1; // mark as DISCOVERED
    int sum=1;
    for(int next: graph[node]) {
        switch(state[next]) {
            case 1: // a back-edge
            case 2: // a forward edge (since DFS is triggered once for every traversal.)
            break;
            case 0: // a discovery edge
            sum += dfs(next);
            if(sum >= n) {
                return n;
            }
            break;
        }
    }
    state[node]=2; // mark as FINISHED
    return sum;
}

void test() {
    int arr[100];
    bool r=false;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    make_graph(arr);
    for(int i=0;i<n;++i) {
        memset(state, 0, sizeof(state));
        if(dfs(i)<n) {
            r = true;
            break;
        }
    }
    if(r) {
        output(arr);
    } else {
        cout << "-1\n";
    }

}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        test();
    }

    return 0;
}