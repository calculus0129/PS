#include <bits/stdc++.h>
using namespace std;
struct pos {
    int x, y;
};
queue<pos> q[1001];
int n, k, s, tx, ty, arr[201][201], checked[201][201];

void work() {
    queue<pos> tq;
    pos f;
    int i, x, y, nx, ny, MOVE[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    while(s--) {
        for(i=1;i<=1000;++i) if(!q[i].empty()) {
            swap(q[i], tq);
            while(!tq.empty())
            {
                f = tq.front(); tq.pop(); x = f.x, y = f.y;
                for(auto dir:MOVE) {
                    nx = x+dir[0], ny = y+dir[1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n&&!arr[nx][ny]) {
                        arr[nx][ny]=i;
                        q[i].push({nx, ny});
                    }
                }
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0,j;i<n;++i) for(j=0;j<n;++j) {
        cin>>arr[i][j];
        if(arr[i][j]) {
            q[arr[i][j]].push({i,j});
            checked[i][j]=1;
        }
    }
    cin>>s>>tx>>ty;
    work();
    cout << arr[tx-1][ty-1];
    return 0;
}
