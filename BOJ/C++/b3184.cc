#include <bits/stdc++.h>
using namespace std;
int m, n, yang, wolf, y, w;
char madang[251][251];
bool visited[251][251];

int dir[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};

void dfs(int i, int j) {
    visited[i][j] = true;
    switch(madang[i][j]) {
        case 'v':
            w++;
            break;
        case 'o':
            y++;
            break;
    }
    for(int k=0, nx, ny;k<4;++k) {
        nx = i+dir[k][0], ny = j+dir[k][1];
        if(!(nx<0 || ny<0 || nx>=m || ny>=n || madang[nx][ny] == '#' || visited[nx][ny])) dfs(nx, ny);
    }
}

void work() {
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) if(madang[i][j] != '#' && !visited[i][j]) {
        y = w = 0;
        dfs(i, j);
        if(y>w) yang += y;
        else wolf += w;
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) cin >> madang[i][j];
    work();
    cout << yang << ' ' << wolf;
    return 0;
}