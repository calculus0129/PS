#include <bits/stdc++.h>
#define INF 2000
using namespace std;

int cave[126][126], costs[126][126];

struct dijk {
    int x, y, cost;
    bool operator<(const dijk & rhs) const { return cost > rhs.cost; }//return costs[x][y]>costs[rhs.x][rhs.y]; }
};

//vector<dijk> g;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, t=0, i, j, x, y, cost, nxtcost, nx, ny;
    const int dir[][2] = {
        {0,1},
        {1,0},
        {0,-1},
        {-1,0},
    };
    dijk nxt;
    priority_queue<dijk> pq;
    cin >> n;
    while(n) {
        for(i=0;i<n;++i) fill(costs[i], costs[i]+n, INF);
        for(i=0;i<n;++i) for(j=0;j<n;++j) cin >> cave[i][j];
        pq.push({0,0,costs[0][0]=cave[0][0]});
        while(!pq.empty()) {
            x = pq.top().x, y = pq.top().y, cost = pq.top().cost, pq.pop();
            if(cost>costs[x][y]) continue;
            for(i=0;i<4;++i) {
                nx=x+dir[i][0], ny=y+dir[i][1];
                if(nx<0||ny<0||nx>=n||ny>=n||costs[nx][ny]<=cost+cave[nx][ny]) continue;
                costs[nx][ny]=nxtcost=cost+cave[nx][ny];
                pq.push({nx, ny, nxtcost});
            }
        }
        cout << "Problem " << ++t << ": " << costs[n-1][n-1] << '\n';
        cin >> n;
    }
    return 0;
}