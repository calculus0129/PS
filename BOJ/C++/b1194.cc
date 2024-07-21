#include <bits/stdc++.h>
using namespace std;
int m, n;
char arr[64][51][51];

struct State {
    int x, y, keys;
};

int dir[4][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};

bool discovered[64][51][51];

int bfs() {
    int ret = 0;
    queue<State> q0,q1;
    queue<State> &que = q0, &tmp = q1;
    int a=-1, b=-1;
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) if(arr[0][i][j] == '0') {
        a = i, b = j;
        break;
    }
    // cout << a << ' ' << b;
    que.push({a, b, 0});
    discovered[0][a][b] = true;
    for(int k=0;k<64;++k) arr[k][a][b] = '.';

    bool reached = false;
    while(!que.empty() && !reached) {
        swap(que, tmp);
        while(!tmp.empty()) {
            auto [x, y, keys] = tmp.front(); tmp.pop();
            for(int i=0,nx,ny;i<4;++i) {
                nx = x + dir[i][0], ny = y + dir[i][1];
                if(nx<0 || ny<0 || nx>=m || ny>=n || arr[keys][nx][ny] == '#' || discovered[keys][nx][ny]) continue;
                discovered[keys][nx][ny] = true;
                switch(arr[keys][nx][ny]) {
                    case '1':
                        reached = true;
                        // cout << "End: " << nx << ", " << ny << '\n';
                        break;
                    case '.':
                        que.push({nx, ny, keys});
                        break;
                    default:
                        // if(arr[keys][nx][ny]>='a') {
                        int nkeys = keys | (1<<arr[keys][nx][ny]-'a');
                        if(keys == nkeys || !discovered[nkeys][nx][ny]) {
                            // cout << "Key: " << nkeys  << ", (nx,ny) = " << nx << ", " << ny << ' ' << arr[nkeys][nx][ny] << '\n';
                            discovered[nkeys][nx][ny] = true;
                            que.push({nx, ny, nkeys});
                        }
                        // }
                }
            }
        }
        ++ret;
        // cout << ret << " th visit end\n";
    }
    return reached?ret:-1;
}

int main() {
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0;i<m;++i) {
        scanf("%s", arr[0][i]);
    }
    for(int i=0,j,k;i<m;++i) for(j=0;j<n;++j) {
        if(arr[0][i][j]>='A' && arr[0][i][j]<'a') {
            for(k=1;k<64;++k) {
                if(k&(1<<arr[0][i][j]-'A')) arr[k][i][j] = '.';
                else arr[k][i][j] = '#';
            }
            arr[0][i][j] = '#';
        } else for(k=1;k<64;++k) arr[k][i][j] = arr[0][i][j];
    }

    cout << bfs();
    return 0;
}