#include <bits/stdc++.h>
using namespace std;
bool mp[1000][1000];
bool check[1000][1000];
int mpp[1000][1000];
int *arr[1000][1000];
int m, n;

int dir[][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0},
};

int work(int x, int y, int* ptr) {
    arr[x][y] = ptr;
    check[x][y]=1;
    int cnt=1, nx, ny, i;
    for(i=0;i<4;++i) {
        nx = x+dir[i][0]; ny = y+dir[i][1];
        if(nx>=0 && ny>=0 && nx<m && ny<n && !check[nx][ny]) {
            cnt += work(nx, ny, ptr);
        }
    }
    return cnt;
}

int work2(int x, int y) {
    int cnt = 1, i, nx, ny;
    set<int*> s;
    for(i=0;i<4;++i) {
        nx = x+dir[i][0]; ny = y+dir[i][1];
        if(nx>=0 && ny>=0 && nx<m && ny<n && !s.count(arr[nx][ny])) {
            cnt += *arr[nx][ny];
            s.insert(arr[nx][ny]);
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(0);
    int i, j, tmp;
    int *zp=new int(0);
    cin >> m >> n;
    string s;
    for(i=0;i<m;++i) {
        cin >> s;
        for(j=0;j<n;++j) {
            check[i][j] = mp[i][j] = s[j]-'0';
        }
    }
    for(i=0;i<m;++i) for(j=0;j<n;++j) {
        if(check[i][j] == 0) {
            tmp = work(i, j, new int);
            *arr[i][j] = tmp;
        }
        else if(mp[i][j]) {
            arr[i][j] = zp;
        }
    }
    //for(int i=0, j, tmp;i<m;++i) for(int j=0;j<n;++j) check[i][j] = mp[i][j];
    // for debug
    /*cout << endl;
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) {
            cout << *arr[i][j];
        }
        cout << "\n";
    }
    cout << endl;*/

    for(i=0;i<m;++i) for(j=0;j<n;++j) if(mp[i][j] == 1) mpp[i][j] = work2(i, j);
    
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) {
            cout << mpp[i][j] % 10;
        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}
