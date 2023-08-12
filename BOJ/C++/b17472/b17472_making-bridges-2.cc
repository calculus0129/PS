#include <bits/stdc++.h>
using namespace std;
int m, n, arr[10][10], v, cost, s[60];
bool visited[10][10];
const bool IS_DEBUG = 0;

struct edge {
    int w, a, b;
};

bool cmp(const edge &a, const edge &b) {
    return a.w > b.w;
}

priority_queue<edge, vector<edge>, bool(*)(const edge &, const edge &)> pq(cmp);

const int dir[][2] {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0}
};

void dfs(int x, int y, int node) {
    visited[x][y] = 1;
    arr[x][y] = node;
    for(int nx, ny, i=0;i<4;++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(nx<0 || nx>=m || ny<0 || ny>=n || !arr[nx][ny] || visited[nx][ny]) continue;
        dfs(nx, ny, node);
    }
}

void dfs_all() {
    for(int i=0, j;i<m;++i) {
        for(j=0;j<n;++j) if(arr[i][j] && !visited[i][j]) {
            dfs(i, j, ++v);
        }
    }
    for(int i=1;i<=v;++i) s[i]=i;
}

void make_edges() {
    // garo
    int prev, dist;
    for(int i=0, j;i<m;++i) {
        prev=0;
        dist=-1;
        for(j=0;j<n;++j) {
            ++dist;
            if(arr[i][j]) {
                if(prev != arr[i][j] && dist>1) pq.push({dist, prev, arr[i][j]});
                prev = arr[i][j];
                dist = -1;
            }
        }
    }
    // sero
    for(int j=0, i;j<n;++j) {
        prev=0;
        dist=-1;
        for(i=0;i<m;++i) {
            ++dist;
            if(arr[i][j]) {
                if(prev != arr[i][j] && dist>1) pq.push({dist, prev, arr[i][j]});
                prev = arr[i][j];
                dist = -1;
            }
        }
    }
}

int find(int a) {
    if(a == s[a]) return a;
    return s[a] = find(s[a]);
}

void mst() {
    int a, b, pa, pb;
    edge tmp;
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        if(IS_DEBUG) cout << tmp.w << ' ' << tmp.a << ' ' << tmp.b << '\n';
        pa = find(a = tmp.a), pb = find(b = tmp.b);
        if(pa==0 || pa==pb) continue;
        cost += tmp.w;
        s[pa] = s[pb] = min(pa, pb);
    }
}

bool is_connected() {
    for(int i=1;i<=v;++i) if(find(i)!=1) return false;
    return true;
}

void debug1() {
    int i, j;
    cout << "v: " << v << '\n';
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

void debug2() {
    for(int i=1;i<=v;++i) {
        cout << "find( " << i << " ): " << find(i) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    for(int i=0, j;i<m;++i) for(j=0;j<n;++j) {
        cin >> arr[i][j];
    }
    dfs_all();
    if(IS_DEBUG) debug1();
    make_edges();
    mst();
    if(IS_DEBUG) debug2();

    cout << (is_connected() ? cost : -1);

    return 0;
}