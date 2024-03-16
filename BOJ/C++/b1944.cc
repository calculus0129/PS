#include <bits/stdc++.h>
using namespace std;
int n, m;
bool mp[51][51];

struct coord {
    int x, y;
};
coord coords[251];
int s[251];

struct edge {
    int a, b, dist;
    bool operator<(const edge &e) const {
        return dist>e.dist;
    }
};

priority_queue<edge> pq;

bool discovered[51][51];

bool checkbound(int x, int y) {
    return x>=0 && y>=0 && x<n && y<n;
}

int dist(const coord &a, const coord &b) {
    int ax = a.x, ay = a.y, bx = b.x, by = b.y, dir[][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    queue<coord> que, tmp;
    coord f;
    int ret = 0, nx, ny;
    memset(discovered, 0, sizeof(discovered));

    que.push({ax, ay});
    discovered[ax][ay] = true;

    while(!que.empty() && !discovered[bx][by]) {
        swap(que, tmp);
        ++ret;
        while(!tmp.empty()) {
            f = tmp.front(); tmp.pop(); ax = f.x, ay = f.y;
            for(int i=0;i<4;++i) {
                nx = ax + dir[i][0], ny = ay + dir[i][1];
                if(!checkbound(nx, ny) || mp[nx][ny] || discovered[nx][ny]) continue;
                discovered[nx][ny] = true;
                que.push({nx, ny});
            }
        }
    }
    return discovered[bx][by]?ret:-1;
}

void addedge(int a, int b) {
    pq.push({a, b, dist(coords[a], coords[b])});
}

int find(int a) {
    if(s[a] == a) return a;
    return s[a] = find(s[a]);
}

int unionize(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa != fb) return s[fa] = s[fb] = min(fa, fb);
    return fa;
}

int main() {
    scanf("%d%d", &n, &m);
    char c;
    int ans = 0;
    for(int i=0;i<=m;++i) s[i] = i;
    for(int i=0, j, cnt=0;i<n;++i) for(j=0;j<n;++j) {
        scanf(" %c", &c);
        if(c == 'S' || c == 'K') {
            coords[cnt++] = {i, j};
        } else mp[i][j] = c=='1';
    }
    for(int i=0, j;i<=m;++i) for(j=i+1;j<=m;++j) addedge(i, j);
    if(pq.top().dist < 0) {
        puts("-1");
    } else {
        int remaining_edge = m, a, b, c;
        while(remaining_edge>0) {
            a = pq.top().a, b = pq.top().b, c = pq.top().dist; pq.pop();
            if(find(a) == find(b)) continue;
            unionize(a, b);
            ans += c;
            --remaining_edge;
        }
        printf("%d", ans);
    }

    return 0;
}