#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
int m, n;

int dir[][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};

int robot(int x, int y, int d) {
    int ret = 0, nx, ny;
    bool r = true, success;
    while(r) {
        if(arr[x][y] == 0) {
            arr[x][y] = 2;
            ++ret;
        }
        success = false;
        for(int i=4;i && !success;--i) {
            d = (d+3)%4;
            nx = x + dir[d][0], ny = y + dir[d][1];
            if(0<=nx && nx<m && 0<=ny && ny<n && arr[nx][ny] == 0) {
                x = nx, y = ny;
                success = true;
            }
        }
        if(!success) {
            nx = x - dir[d][0], ny = y - dir[d][1];
            if(!(0<=nx && nx<m && 0<=ny && ny<n) || arr[nx][ny] == 1) {
                r = false;
            } else {
                x = nx, y = ny;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    int a, b, d; cin >> a >> b >> d;
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) {
        cin >> arr[i][j];
    }

    cout << robot(a, b, d);

    return 0;
}