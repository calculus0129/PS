#include <bits/stdc++.h>
using namespace std;
int m, n, arr[1000][1000], spread[1000][1000];

struct pos {
    int x, y;
    pos operator+(const pos &rhs) {
        return pos({x+rhs.x, y+rhs.y});
    }
};

void work() {
    pos f;
    queue<pos> q1, q2, tq1, tq2, spread_now;
    int x, y, nx, ny, MOVE[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) {
        if (arr[i][j]==0) continue;
        if (arr[i][j]==1) {
            q1.push({i,j});
        }
        else if(arr[i][j]==2) {
            q2.push({i,j});
        }
        spread[i][j]=1;
    }
    while (!q1.empty() || !q2.empty()) {
        swap(q1, tq1);
        swap(q2, tq2);
        while(!tq1.empty()) {
            f = tq1.front();
            tq1.pop();
            x = f.x, y = f.y;
            if(arr[x][y]==3) continue;
            for(auto dir: MOVE) {
                nx = x+dir[0], ny = y+dir[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && (arr[nx][ny]==0 || !spread[nx][ny] && arr[nx][ny]==2)) {
                    arr[nx][ny]+=1;
                    q1.push({nx, ny});
                    spread_now.push({nx, ny});
                }
            }
        }

        while(!tq2.empty()) {
            f = tq2.front();
            tq2.pop();
            x = f.x, y = f.y;
            if(arr[x][y]==3) continue;
            for(auto dir: MOVE) {
                nx = x+dir[0], ny = y+dir[1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && (arr[nx][ny]==0 || !spread[nx][ny] && arr[nx][ny]==1)) {
                    arr[nx][ny]+=2;
                    q2.push({nx, ny});
                    spread_now.push({nx, ny});
                }
            }
        }

        while(!spread_now.empty()) {
            f = spread_now.front(); spread_now.pop();
            spread[f.x][f.y]=1;
        }
    }
}

int main()
{
    int ans[] = {0, 0, 0};
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) {
        cin >> arr[i][j];
    }
    work();
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) if(arr[i][j]>0) {
        ans[arr[i][j]-1]++;
    }
    for(int i=0;i<3;++i) cout << ans[i] << " ";
    return 0;
}
