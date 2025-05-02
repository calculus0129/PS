#include <bits/stdc++.h>
using namespace std;
int n, arr[102][102];

// https://qspblog.com/blog/cpp-c-%EC%8B%9C%EC%9E%91%ED%95%B4%EB%B3%B4%EA%B8%B0-switch-case-%EC%99%80-enum
enum Direction {
    RIGHT,
    DOWN,
    LEFT,
    UP,
};

const int DIR[][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};

Direction dir[10200];

void moveTail(int tx, int ty) {
    int num = arr[tx][ty]--;
    for(int i=0, nx, ny;i<4;++i) {
        nx = tx + DIR[i][0], ny = ty + DIR[i][1];
        if(arr[nx][ny] == num + 1) {
            moveTail(nx, ny);
        }
    }
}

int findLength(int hx, int hy) {
    int ret = arr[hx][hy]; // initial
    for(int i=0, nx, ny;i<4;++i) {
        nx = hx + DIR[i][0], ny = hy + DIR[i][1];
        if(ret < arr[nx][ny]) ret = arr[nx][ny];
    }
    return ret;
}

bool getTail(int &tx, int &ty) {
    for(int i=0, nx, ny;i<4;++i) {
        nx = tx + DIR[i][0], ny = ty + DIR[i][1];
        if(arr[nx][ny] == 1) {
            tx = nx, ty = ny;
            return true;
        }
    }
    return false;
}

void debug(int x, int y, int t, int tx, int ty) {
    cout << "Time: " << t << " (" << x << ", " << y << ")\n";
    cout << "Tail: (" << tx << ", " << ty << ")\n";
    for(int i=0, j;i<=n+1;++i) {
        for(j=0;j<=n+1;++j) {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<=n;++i) {
        arr[i][0] = arr[n+1][i] = arr[n+1-i][n+1] = arr[0][n+1-i] = -2;
    }
    int k; cin >> k;
    for(int i=0,a,b;i<k;++i) {
        cin >> a >> b;
        arr[a][b] = -1;
    }
    int l,x,y;
    cin >> l;
    char c;
    // IMOS strategy
    while(l--) {
        cin >> x >> c;
        dir[x] = (Direction)(2 + (c == 'L' ? 1 : -1));
    }
    for(int t=1;t<=10111;++t) {
        dir[t] = (Direction)((dir[t-1] + dir[t]) % 4);
    }
    int t=1;
    x = 1, y = 2;
    arr[1][1] = 1;
    int tx = 1, ty = 1; // tail's coordinate
    while(arr[x][y] > -2 && arr[x][y] < 1) { // arr[x][y] == 1 would be more intuistic
        l = findLength(x, y);
        if(arr[x][y] >= 0) { // no apple
            moveTail(tx, ty);
            arr[x][y] = l;
            assert(getTail(tx, ty));
        } else { // with apple
            arr[x][y] = l + 1;
        }
        // Move Head x,y
        x += DIR[dir[t]][0];
        y += DIR[dir[t]][1];
        // debug(x, y, t, tx, ty);
        ++t;
    }
    cout << t;

    return 0;
}