#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int n, combined[21][21], ans;
vector<vector<int>> arr;

int mx(vector<vector<int>> const & a) {
    int ret=0;
    for(int i=1,j;i<=n;++i) for(j=1;j<=n;++j) ret = max(ret, a[i][j]);
    return ret;
}

vector<vector<int>> u(vector<vector<int>> ar) {
    int i, j, a, x, y;
    for(j=1;j<=n;++j) {
        for(i=1;i<=n;++i) if(a=ar[i][j]) {
            ar[x=i][j]=0;
            while(x>1 && !ar[x-1][j]) x--;
            if(x>1 && ar[x-1][j]==a && !combined[x-1][j]) {
                combined[x-1][j]=1;
                ar[x-1][j]<<=1;
            } else {
                ar[x][j]=a;
            }
        }
        for(i=1;i<=n;++i) combined[i][j]=0;
    }
    return ar;
}

vector<vector<int>> d(vector<vector<int>> ar) {
    int i, j, a, x, y;
    for(j=1;j<=n;++j) {
        for(i=n;i>=1;--i) if(a=ar[i][j]) {
            ar[x=i][j]=0;
            while(x<n && !ar[x+1][j]) x++;
            if(x<n && ar[x+1][j]==a && !combined[x+1][j]) {
                combined[x+1][j]=1;
                ar[x+1][j]<<=1;
            } else {
                ar[x][j]=a;
            }
        }
        for(i=1;i<=n;++i) combined[i][j]=0;
    }
    return ar;
}

vector<vector<int>> l(vector<vector<int>> ar) {
    int i, j, a, x, y;
    for(i=1;i<=n;++i) {
        for(j=1;j<=n;++j) if(a=ar[i][j]) {
            ar[i][y=j]=0;
            while(y>1 && !ar[i][y-1]) y--;
            if(y>1 && ar[i][y-1]==a && !combined[i][y-1]) {
                combined[i][y-1]=1;
                ar[i][y-1]<<=1;
            } else {
                ar[i][y]=a;
            }
        }
        for(j=1;j<=n;++j) combined[i][j]=0;
    }
    return ar;
}

vector<vector<int>> r(vector<vector<int>> ar) {
    int i, j, a, x, y;
    for(i=1;i<=n;++i) {
        for(j=n;j>=1;--j) if(a=ar[i][j]) {
            ar[i][y=j]=0;
            while(y<n && !ar[i][y+1]) y++;
            if(y<n && ar[i][y+1]==a && !combined[i][y+1]) {
                combined[i][y+1]=1;
                ar[i][y+1]<<=1;
            } else {
                ar[i][y]=a;
            }
        }
        for(j=1;j<=n;++j) combined[i][j]=0;
    }
    return ar;
}

void work() {
    int step=0;
    ans=mx(arr);
    vector<vector<int>> tarr, ut, dt, lt, rt;
    queue<vector<vector<int>>> q, tmp;
    q.push(arr);
    while(++step<=5) {
        while(!q.empty()) {
            tarr = q.front(); q.pop();
            ut = u(tarr);
            dt = d(tarr);
            lt = l(tarr);
            rt = r(tarr);
            ans = max(ans, mx(ut));
            ans = max(ans, mx(dt));
            ans = max(ans, mx(lt));
            ans = max(ans, mx(rt));
            tmp.push(ut);
            tmp.push(dt);
            tmp.push(lt);
            tmp.push(rt);
        }
        swap(q, tmp);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    arr=vector(n+1, vector(n+1, 0));
    int i, j;
    for(i=1;i<=n;++i) for(j=1;j<=n;++j) cin >> arr[i][j];
    work();
    cout << ans;

    return 0;
}