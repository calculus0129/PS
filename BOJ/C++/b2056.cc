#include <bits/stdc++.h>
using namespace std;
int n, arr[10101], t[10101], dt[10101];

unordered_map<int, vector<int>> alist;

void input() {
    cin >> n;
    for(int i=1, m, j;i<=n;++i) {
        cin >> t[i];
        cin >> m;
        alist[i].resize(m);
        for(j=0;j<m;++j) {
            cin >> alist[i][j];
        }
    }
}

int cnt;
bool discovered[10001];

void dfs(int node) {
    discovered[node] = true;
    for(int next: alist[node]) if(!discovered[next]) { // see only discovery edges!
        dfs(next);
    }
    arr[cnt++] = node;
}

void toposort() {
    for(int i=n;i>0;--i) if(!discovered[i]) dfs(i);
}

void dp() {
    // dt[arr[1]] = t[arr[1]];
    for(int i=0;i<n;++i) {
        for(int j: alist[arr[i]]) dt[arr[i]] = max(dt[arr[i]], dt[j]);
        dt[arr[i]] += t[arr[i]];
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    toposort();
    dp();
    cout << *max_element(dt+1, dt+n+1);
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int n, arr[10101], t[10101], dt[10101];

unordered_map<int, vector<int>> alist;

void input() {
    
}

void toposort() {

}

void dp() {
    
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    toposort();
    dp();
    cout << *max_element(arr, arr+n);
    return 0;
}
*/