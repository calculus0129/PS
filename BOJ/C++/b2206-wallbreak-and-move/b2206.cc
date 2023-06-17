#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool mp[1001][1001];
int m, n;
int d1[1001][1001], d2[1001][1001];

/*void bfs(int px, int py, int** d) {
  queue<pii> que, tmp;
  que.push({px, py});
  int x, y, nx, ny, i;
  int dir[][2] = {
      {0, 1},
      {1, 0},
      {0, -1},
      {-1, 0},
  };
  bool check[1001][1001];
  memset(check, 0, sizeof(check));
  int cnt = 0;
  while (!que.empty()) {
    swap(que, tmp);
    while (!tmp.empty()) {
      x = tmp.front().first;
      y = tmp.front().second;
      tmp.pop();
      check[x][y] = 1;
      d[x][y] = cnt;
      for (i = 0; i < 4; ++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mp[nx][ny] ||
            check[nx][ny])
          continue;
        check[nx][ny] = 1;
        que.push({nx, ny});
      }
    }
    ++cnt;
  }
}*/

int main() {
  int ans=1000001;
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);

  char buf[1010];
  cin >> m >> n;
  for (int i = 0, j; i < m; ++i) {
    cin >> buf;
    for (j = 0; j < n; ++j) {
      mp[i][j] = buf[j] == '1';
    }
  }

  queue<pii> que, tmp;
  int x, y, nx, ny, i, j, k;
  const int dir[][2] = {
      {0, 1},
      {1, 0},
      {0, -1},
      {-1, 0},
  };
  bool check1[1001][1001], check2[1001][1001];
  int cnt = 1;
  que.push({0, 0});
  memset(check1, 0, sizeof(check1));

  while (!que.empty()) {
    swap(que, tmp);
    while (!tmp.empty()) {
      x = tmp.front().first;
      y = tmp.front().second;
      tmp.pop();
      check1[x][y] = 1;
      d1[x][y] = cnt;
      for (i = 0; i < 4; ++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mp[nx][ny] || check1[nx][ny])
          continue;
        check1[nx][ny] = 1;
        que.push({nx, ny});
      }
    }
    ++cnt;
  }
  if(check1[m-1][n-1]) ans = d1[m-1][n-1];

  cnt=1;
  que.push({m - 1, n - 1});
  memset(check2, 0, sizeof(check2));

  while (!que.empty()) {
    swap(que, tmp);
    while (!tmp.empty()) {
      x = tmp.front().first;
      y = tmp.front().second;
      tmp.pop();
      check2[x][y] = 1;
      d2[x][y] = cnt;
      for (i = 0; i < 4; ++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || mp[nx][ny] || check2[nx][ny])
          continue;
        check2[nx][ny] = 1;
        que.push({nx, ny});
      }
    }
    ++cnt;
  }
  /*
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      cout << d1[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  for (i = 0; i < m; ++i) {
    for (j = 0; j < n; ++j) {
      cout << d2[i][j] << " ";
    }
    cout << endl;
  }*/
  int x1=1000001, x2=1000001;
  for(i=0;i<m;++i) for(j=0;j<n;++j) if(mp[i][j]) {
    x1 = x2 = 1000001;
    for(k=0;k<4;++k) {
      nx = i+dir[k][0], ny = j+dir[k][1];
      if(nx<0||ny<0||nx>=m||ny>=n) continue;
      if(check1[nx][ny]) x1 = min(x1, d1[nx][ny]);
      if(check2[nx][ny]) x2 = min(x2, d2[nx][ny]);
    }
    ans = min(ans, x1+x2+1);
  }
  if(ans==1000001) cout << -1;
  else cout << ans;

  return 0;
}