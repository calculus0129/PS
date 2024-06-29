#include <bits/stdc++.h>
using namespace std;
bool arr[1010][1010];
bool land[1010][1010];
bool visited[1010][1010];
typedef pair<int, int> pii;
int m, n;
int dir[][2] = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1},
};

bool check(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n;
}

queue<pii> que;

void bfs() {
    while(!que.empty()) {
        pii p = que.front(); que.pop();
        int x = p.first, y = p.second, nx, ny;
        for(int i=0;i<4;++i) {
            nx = x+dir[i][0], ny = y+dir[i][1];
            if(check(nx, ny) && !arr[nx][ny] && land[nx][ny]) {
                land[nx][ny] = false;
                que.push({nx, ny});
            }
        }
    }
}

void getland() {
    memset(&land[0][0], 1, sizeof(land));
    for(int i=0;i<m;++i) {
        if(!arr[i][0]) {
            que.push({i,0});
            land[i][0]=false;
        }
        if(!arr[i][n-1]) {
            que.push({i,n-1});
            land[i][n-1]=false;
        }
    }
    for(int j=1;j<n-1;++j) {
        if(!arr[0][j]) {
            que.push({0, j});
            land[0][j] = false;
        }
        if(!arr[m-1][j]) {
            que.push({m-1, j});
            land[m-1][j] = false;
        }
    }
    bfs();
    // for(int i=0, j;i<m;++i) {
    //     for(j=0;j<n;++j) cout << land[i][j];
    //     cout << '\n';
    // }
}

int dfs(int x, int y) {
    int ret = 0;
    visited[x][y] = true;
    for(int i=0, nx, ny;i<4;++i) {
        nx = x+dir[i][0], ny = y+dir[i][1];
        if(!check(nx, ny) || visited[nx][ny]) continue;
        if(land[nx][ny]) ++ret;
        else ret += dfs(nx, ny);
    }
    return ret;
}

int getperimeter() {
    int ret = 0;
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) if(!land[i][j] && !visited[i][j]) {
        ret += dfs(i, j);
        // cout << ret << '\n';
    }
    for(int i=0;i<m;++i) {
        ret += land[i][0];
        ret += land[i][n-1];
    }
    for(int i=0;i<n;++i) {
        ret += land[0][i];
        ret += land[m-1][i];
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    char c;
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) {
        cin >> c;
        arr[i][j] = c-'0';
    }
    getland();
    cout << getperimeter();

    return 0;
}