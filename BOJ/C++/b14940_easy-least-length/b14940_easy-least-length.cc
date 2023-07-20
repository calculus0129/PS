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
    p t;
    int cnt=0, x, y, nx, ny;
    q.push({sx, sy});
    while(!q.empty()) {
        swap(q, tmp);
        while(!tmp.empty()) {
            t = tmp.front(); tmp.pop();
            x = t.first, y = t.second;
            arr[x][y] = cnt;
            visited[x][y] = 1;
            for(auto i: dir) {
                nx = x + i[0], ny = y + i[1];
                if(nx<0 || ny<0 || nx>=m || ny >= n || arr[nx][ny]==0) continue;
                q.push({nx, ny});
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