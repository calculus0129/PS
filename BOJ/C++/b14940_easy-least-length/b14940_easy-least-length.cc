#include <bits/stdc++.h>
using namespace std;
int m, n;
int arr[1010][1010];
bool visited[1010][1010];
typedef pair<int,int> p;

int dir[][2] = {
    {-1,0},
    {0,-1},
    {1,0},
    {0,1},
};

void bfs_all(int sx, int sy) {
    queue<p> q, tmp;
    int cnt=0, x, y, nx, ny, i;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()) {
        swap(q, tmp);
        while(!tmp.empty()) {
            x = tmp.front().first, y = tmp.front().second; tmp.pop();
            arr[x][y] = cnt;
            for(i=0;i<4;++i) {
                nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && arr[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
            }
        }
        ++cnt;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    int sx, sy;
    for(int i=0, j, a;i<m;++i) for(j=0;j<n;++j) {
        cin >> a;
        if(a==2) {
            sx = i, sy = j;
        } else arr[i][j] = -a;
    }
    bfs_all(sx, sy);
    for(int i=0, j;i<m;++i) {
        for(j=0;j<n;++j) cout << arr[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}