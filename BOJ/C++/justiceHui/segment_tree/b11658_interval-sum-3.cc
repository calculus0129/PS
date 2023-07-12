#include <bits/stdc++.h>
using namespace std;
const size_t WIDTH=10;
const size_t SIZE = 1<<WIDTH;
size_t segtree[SIZE<<1][SIZE<<1];
int n;

void make_tree() {
    size_t wx=WIDTH, wy, i, j, ex, ey;
    wy=WIDTH;
    while(wy--) {
        for(j=1<<wy,ey=j<<1;j<ey;++j) for(i=1<<wx,ex=i<<1;i<ex;++i) {
            segtree[i][j] = segtree[i][j<<1] + segtree[i][j<<1|1];
        }
    }
    while(wx--) {
        wy=WIDTH;
        for(i=1<<wx,ex=i<<1;i<ex;++i) for(j=1<<wy,ey=j<<1;j<ey;++j) {
            segtree[i][j] = segtree[i<<1][j] + segtree[i<<1|1][j];
        }
        while(wy--) {
            for(j=1<<wy,ey=j<<1;j<ey;++j) for(i=1<<wx,ex=i<<1;i<ex;++i) {
                segtree[i][j] = segtree[i][j<<1] + segtree[i][j<<1|1];
            }
        }
    }
}

void query(int p1, int p2, vector<int>& v, int s=0, int e=SIZE-1, int node=1) {
    if(p1 <= s && e <= p2) {
        v.push_back(node);
        return;
    }
    if(e < p1 || s > p2) return;
    int m = s + e >> 1;
    query(p1, p2, v, s, m, node<<1);
    query(p1, p2, v, m+1, e, node<<1|1);
}

/*
int query(int x1, int y1, int x2, int y2, int sx=0, int ex=SIZE-1, int sy=0, int ey=SIZE-1, int nodex=1, int nodey=1) {
    if (x1<=sx && ex<=x2 && y1<=sy && ey<=y2) return segtree[nodex][nodey];
    if (x2<sx || x1>ex || y2<sy || y1>ey) return 0;
    int mx=sx+ex>>1, my=sy+ey>>1;
    return \
    query(x1, y1, x2, y2, sx, mx, sy, my, nodex<<1, nodey<<1) + \
    query(x1, y1, x2, y2, mx+1, ex, sy, my, nodex<<1|1, nodey<<1) + \
    query(x1, y1, x2, y2, sx, mx, my+1, ey, nodex<<1, nodey<<1|1) + \
    query(x1, y1, x2, y2, mx+1, ex, my+1, ey, nodex<<1|1, nodey<<1|1);
}
*/
void update(int x, int y, size_t val) {
    int nx = SIZE+x, ny = SIZE+y, dif = val-segtree[nx][ny];
    if(dif) do {
        ny = SIZE+y;
        do segtree[nx][ny]+=dif;
        while(ny>>=1);
    } while(nx>>=1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m;
    size_t sum, w, a, b, c, d;
    cin >> n >> m;
    for(int i=0, j; i<n;++i) for(j=0;j<n;++j) cin >> segtree[i+SIZE][j+SIZE];
    make_tree();
    vector<int> vx, vy;
    while(m--) {
        cin >> w;
        if(w==0) {
            cin >> a >> b >> c;
            update(a-1, b-1, c);
        } else {
            cin >> a >> b >> c >> d;
            query(a-1, c-1, vx);
            query(b-1, d-1, vy);
            sum=0;
            for(const int &i: vx) for(const int &j: vy) sum += segtree[i][j];
            cout << sum << '\n';
            vx.clear();
            vy.clear();
        }
    }
    return 0;
}