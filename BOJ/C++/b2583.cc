#include <bits/stdc++.h>
using namespace std;
int m, n;
bool arr[101][101];
vector<int> ans;

int dir[][2] = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1}
};

int dfs(int x, int y) {
    int ret = 1;
    arr[x][y] = true;
    for(int nx, ny, i=0;i<4;++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx>=0 && nx<m && ny>=0 && ny<n && !arr[nx][ny]) ret += dfs(nx, ny);
    }
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int k;
    cin >> n >> m >> k;
    while(k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i=a, j;i<c;++i) for(j=b;j<d;++j) {
            arr[i][j] = true;
        }
    }
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) if(!arr[i][j]) {
        ans.push_back(dfs(i, j));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto a: ans) cout << a << ' ';
    return 0;
}