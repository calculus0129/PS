#include <bits/stdc++.h>
using namespace std;
char mp[101][101], arr[101][101];
bool discovered[101][101], visited[101][101], dfs_visiting[101][101];
int m, n;

auto cmp = [](pair<int, int> x, pair<int, int> y) {
    return mp[x.first][x.second]<mp[y.first][y.second];
};

priority_queue<pair<int, int>, vector<pair<int, int>>, bool(*)(pair<int, int>, pair<int, int>)> que(cmp);

bool checkboundary(int x, int y) {
    return x>=0 && x<m && y>=0 && y<n;
}

int dir[][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};

int dfs(int x, int y) {
    int ret = 1, nx, ny;
    dfs_visiting[x][y] = true;
    for(int i=0;i<4;++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(checkboundary(nx, ny) && discovered[nx][ny] && !dfs_visiting[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

bool done() {
    int i, j, x, y, cnt=0;
    bool init=false;
    
    for(i=0;i<m;++i) for(j=0;j<n;++j) if(discovered[i][j]) {
        if(!init) {
            init = true;
            x = i;
            y = j;
        }
        ++cnt;
    }
    memset(dfs_visiting, 0, sizeof(dfs_visiting));

    return dfs(x, y) == cnt;
}

void fill(int x, int y) {
    char num = mp[x][y];
    int ax = max(0, x - num), ay = max(0, y - num), bx = min(m-1, x + num), by = min(n-1, y + num);
    for(int i=ax, j;i<=bx;++i) for(j=ay;j<=by;++j) if(!discovered[i][j]) {
        discovered[i][j] = true;
        que.push({i, j});
        arr[i][j] = num;
    }
    visited[x][y] = true;
}

void spread() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, bool(*)(pair<int, int>, pair<int, int>)> tmp(cmp);
    swap(que, tmp);
    while(!tmp.empty()) {
        int x = tmp.top().first, y = tmp.top().second;
        // cout << (int)mp[x][y] << ' ';
        tmp.pop();
        fill(x, y);
    }
    // cout << '\n';
}

void replace() {
    copy(arr[0], &arr[0][0]+101*101, mp[0]);
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) {
        cin >> mp[i][j];
        mp[i][j]-='0';
        if(mp[i][j]>0) {
            discovered[i][j] = true;
            que.push({i, j});
        }
    }
    copy(mp[0], &mp[0][0]+101*101, arr[0]);
    int cnt = 0;
    while(!done()) {
        spread();
        replace();
        ++cnt;
    }
    cout << cnt;

    return 0;
}