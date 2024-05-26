#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int m, n;
int arr[101][101], narr[101][101];
bool discovered[101][101], visited[101][101];
queue<pii> que;

int cir[][2] = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};

void bfs_con() {
    int x, y;
    while(!que.empty()) {
        x = que.front().first, y = que.front().second; que.pop();
        visited[x][y]=true;
        for(int i=0, nx, ny;i<4;++i) {
            nx = x + cir[i][0], ny = y + cir[i][1];
            if(nx>=0 && ny>=0 && nx<m && ny<n && !discovered[nx][ny] && arr[nx][ny]) {
                discovered[nx][ny]=true;
                que.push({nx, ny});
            }
        }
    }
}

void init() {
    memset(discovered, 0, sizeof(discovered));
    memset(visited, 0, sizeof(visited));
}

bool connected() {
    init();
    int cnt=0;
    for(int i=0,j;i<m && cnt<2;++i) for(j=0;j<n && cnt<2;++j) if(arr[i][j] && !discovered[i][j]) {
        discovered[i][j] = true;
        que.push({i, j});
        bfs_con();
        ++cnt;
    }
    return cnt<2;
}

void uni_spread(int x, int y) {
    int tgt = arr[x][y];
    for(int i=-tgt, j, nx, ny;i<=tgt;++i) for(j=-tgt;j<=tgt;++j) {
        nx=x+i, ny=y+j;
        if(nx>=0 && ny>=0 && nx<m && ny<n && narr[nx][ny]<tgt) {
            narr[nx][ny] = tgt;
        }
    }
}

void spread(int tgt) {
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) if(arr[i][j] == tgt) uni_spread(i, j);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    char buf[101];
    for(int i=0, j;i<m;++i) {
        cin >> buf;
        for(j=0;j<n;++j) {
            arr[i][j] = buf[j] - '0';
        }
    }
    int ans=0;

    while(!connected()) {
        ++ans;
        memcpy(narr, arr, sizeof(narr));
        for(int i=1;i<=5;++i) {
            spread(i);
        }
        memcpy(arr, narr, sizeof(narr));
        // for(int i=0,j;i<m;++i) {
        //     for(j=0;j<n;++j) {
        //         cout << arr[i][j];
        //     }
        //     cout << '\n';
        // }
    }
    cout << ans;

    return 0;
}