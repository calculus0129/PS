#include <bits/stdc++.h>
using namespace std;
int w, h;
bool arr[51][51];
bool discovered[51][51];

const int dir[][2] = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1},
};

bool isvalid(int x, int y) {
    return x>=0 && y>=0 && x<h && y<w;
}

void dfs(int x, int y) {
    discovered[x][y] = true;
    for(int i=0, nx, ny;i<8;++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(isvalid(nx, ny) && arr[nx][ny] && !discovered[nx][ny]) dfs(nx, ny);
    }
}

int dfs() {
    memset(discovered, 0, sizeof(discovered));
    int ret=0;
    for(int i=0,j;i<h;++i) for(j=0;j<w;++j) if(arr[i][j] && !discovered[i][j]) {
        dfs(i, j);
        ++ret;
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> w >> h;
    while(w) {
        for(int i=0,j,a;i<h;++i) for(j=0;j<w;++j) {
            cin >> a;
            arr[i][j] = a == 1;
        }
        cout << dfs() << '\n';
        cin >> w >> h;
    }
    return 0;
}