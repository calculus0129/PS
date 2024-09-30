#include <bits/stdc++.h>
#define CHECK(a,b) (0 <= (a) && (a) < m && 0 <= (b) && (b) < n)
using namespace std;
int m,n;
int dir[][2] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

bool minerals[101][101];
int clusterMap[101][101];

int locate(int height, bool right) {
    int i;
    if(right) for(i=n-1;i>=0 && !clusterMap[height][i];--i);
    else for(i=0;i<n && !clusterMap[height][i];++i);
    return i;
}

void cluster(int x, int y, int color) {
    if(!CHECK(x, y) || clusterMap[x][y] != 1) return;
    clusterMap[x][y] = color;
    for(int i=0,nx,ny;i<4;++i) {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        cluster(nx, ny, color);
    }
}

int fallHeight(int color) {
    int i, j, h1, h2, ret=999;
    for(i=0;i<n;++i) {
        h1 = h2 = m;
        for(j=0;j<m;++j) {
            if(clusterMap[j][i]) {
                if(clusterMap[j][i] == color) {
                    h1=j;
                    h2=m;
                }
                else if(h1 != m && h2 == m) h2=j;
            }
        }
        if(h1!=m) ret = min(ret, h2-h1-1);
    }
    return ret==999 ? 0 : ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    int i,j, T, x;
    for(i=0;i<m;++i) {
        string s;
        cin >> s;
        for(j=0;j<n;++j) {
            if(s[j] == 'x') {
                minerals[i][j] = true;
            }
        }
    }
    cin >> T;
    for(int test=0;test<T;++test) {
        for(i=0;i<m;++i) for(j=0;j<n;++j) {
            clusterMap[i][j] = minerals[i][j];
        }
        cin >> x;
        x = m - x;
        int y = locate(x, test&1);
        // Location Debugging
        // cout << "locate: " << x << ' ' << y << '\n';
        if(y<0 || y>=n) continue;

        minerals[x][y] = false;
        clusterMap[x][y] = 0;

        // Clustering
        cluster(x+1, y, 2);
        cluster(x, y+(test&1?-1:1), 3);
        cluster(x-1, y, 4);
        // Print out the clusters (Debug)
        // for(i=0;i<m;++i) {
        //     for(j=0;j<n;++j) {
        //         cout << clusterMap[i][j];
        //     }
        //     cout << endl;
        // }

        // Falling
        for(int c=2, h;c<=4;++c) {
            h = fallHeight(c);
            if(h) {
                // Debug
                // cout << "c fallHeight(c): " << c << ' ' << h << endl;
                for(i=m-1;~i;--i) for(j=0;j<n;++j) if(clusterMap[i][j] == c) {
                    minerals[i][j] = false;
                    minerals[i+h][j] = true;
                }
                break;
            }
        }
        // Print out the result (Debug)
        // for(i=0;i<m;++i) {
        //     for(j=0;j<n;++j) {
        //         cout << (minerals[i][j]? 'x' : '.');
        //     }
        //     cout << '\n';
        // }
        // Debugging
        // cout << endl;
    }

    // Print out the result
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) {
            cout << (minerals[i][j]? 'x' : '.');
        }
        cout << '\n';
    }
    return 0;
}