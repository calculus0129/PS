#include <bits/stdc++.h>
using namespace std;

int arr[51][51], rmmap[51][51], r, c ,t, air_upper;

const int dir[][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1},
};

const int rdir[][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};

void input() {
    cin >> r >> c >> t;
    for(int i=0, j;i<r;++i) for(j=0;j<c;++j) {
        cin >> arr[i][j];
        if(arr[i][j]==-1 && air_upper==0) air_upper = i;
    }
    for(int i=0, j, k, x, y;i<r;++i) for(j=0;j<c;++j) for(k=0;k<4;++k) {
        x=i+dir[k][0], y=j+dir[k][1];
        if(x>=0 && y>=0 && x<r && y<c && arr[x][y]>=0) ++rmmap[i][j];
    }
}

void diffuse() {
    int newarr[51][51];
    memset(newarr, 0, sizeof(newarr));
    for(int i=0, j, k, x, y;i<r;++i) for(j=0;j<c;++j) for(k=0;k<4;++k) {
        x=i+dir[k][0], y=j+dir[k][1];
        if(x>=0 && y>=0 && x<r && y<c && arr[x][y]>=0) newarr[x][y] += arr[i][j]/5;
    }
    for(int i=0,j;i<r;++i) for(j=0;j<c;++j) {
        newarr[i][j] += arr[i][j] - arr[i][j]/5*rmmap[i][j];
    }
    swap(arr, newarr);
}

void cw() {
    int idx=0;
    int x=air_upper-1,y=0, nx, ny;
    while(true) {
        nx=x+dir[idx][0], ny=y+dir[idx][1];
        if(nx>=0 && ny>=0 && nx<=air_upper && ny<c) {
            if(arr[nx][ny]>=0) arr[x][y]=arr[nx][ny];
            else {
                arr[x][y]=0;
                break;
            }
            x=nx,y=ny;
        }
        else ++idx;
    }
}


void ccw() {
    int idx=0;
    int x=air_upper+2,y=0, nx, ny;
    while(true) {
        nx=x+rdir[idx][0], ny=y+rdir[idx][1];
        if(nx>air_upper && ny>=0 && nx<r && ny<c) {
            if(arr[nx][ny]>=0) arr[x][y]=arr[nx][ny];
            else {
                arr[x][y]=0;
                break;
            }
            x=nx,y=ny;
        }
        else ++idx;
    }
}

void wind() {
    cw();
    ccw();
}

// void debug() {
//     for(int i=0, j;i<r;++i) {
//         for(j=0;j<c;++j) cout << arr[i][j] << ' ';
//         cout << '\n';
//     }
// }

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    input();
    while(t--) {
        diffuse();
        wind();
    }
    int ans = 0;
    for(int i=0,j;i<r;++i) for(j=0;j<c;++j) if(j!=0 || i<air_upper || i>air_upper+1) ans += arr[i][j];
    // debug();
    cout << ans;

    return 0;
}