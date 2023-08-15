#include <bits/stdc++.h>
using namespace std;
const bool IS_DEBUG = 1;
char arr[101][101];
bool visited[101][101], haskey[26];
int m, n, ans, vcnt;

const int dir[][2] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0},
};

bool penetrable(char c) {
    return c == '.' || c == '$' || c>='a' && c<='z' || c!='*' && haskey[c-'A'];
}

void dfs(int x, int y) {
    visited[x][y]=1;
    ++vcnt;
    if(arr[x][y] != '.') {
        if(arr[x][y] == '$') ++ans;
        else if(arr[x][y] >= 'a') haskey[arr[x][y]-'a'] = 1;
        arr[x][y] = '.';
    }
    //if(IS_DEBUG) arr[x][y]='#';
    int nx, ny;
    for(int i=0;i<4;++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && penetrable(arr[nx][ny])) {
            dfs(nx, ny);
        }
    }
}

void steal_quick() {
    int i, j;
    for(i=0;i<m;++i) fill(visited[i], visited[i]+n, 0);

    for(i=0;i<m;++i) {
        if(penetrable(arr[i][0]) && !visited[i][0]) {
            dfs(i, 0);
        }
        if(penetrable(arr[i][n-1]) && !visited[i][n-1]) {
            dfs(i, n-1);
        }
    }
    for(j=1;j<n-1;++j) {
        if(penetrable(arr[0][j]) && !visited[0][j]) {
            dfs(0, j);
        }
        if(penetrable(arr[m-1][j]) && !visited[m-1][j]) {
            dfs(m-1, j);
        }
    }
}

void solve() {
    ans = vcnt = 0;
    int pv;
    do {
        pv = vcnt;
        vcnt = 0;
        steal_quick();
    }
    while(pv!=vcnt);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    string s;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        for(int i=0, j;i<m;++i) for(j=0;j<n;++j) cin >> arr[i][j];
        cin >> s;
        fill(haskey, haskey+26, 0);
        if(s!="0") {
            for(char c: s) {
                haskey[c-'a'] = 1;
            }
        }
        solve();
        cout << ans << '\n';
    }
    return 0;
}