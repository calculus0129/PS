#include <bits/stdc++.h>
using namespace std;
int arr[15][15];
int m, n, k, x, y;

void input() {
    cin >> m >> n >> k;
    if(k==0) {
        x = m-1;
        y = n-1;
    } else {
        k--;
        x = k/n;
        y = k%n;
    }
}

void init(int sx, int sy, int ex, int ey) {
    for(int i=sx;i<=ex;++i) arr[i][sy] = 1;
    for(int i=sy;i<=ey;++i) arr[sx][i] = 1;
}

int work(int sx, int sy, int ex, int ey) {
    init(sx, sy, ex, ey);
    for(int i=sx+1, j;i<=ex;++i) {
        for(j=sy+1;j<=ey;++j) {
            arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    return arr[ex][ey];
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    cout << work(0,0,x,y)*work(x,y,m-1,n-1);
    return 0;
}