#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
unsigned int ans=2500*13*100;
vector<vector<int>> dist;
int chosen[13];

struct coord {
    int x, y;
};

static unsigned int d (const coord a, const coord b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

static unsigned int citychickendist() {
    unsigned int ret=0;
    for(int i, j=0, md;j<s;++j) {
        md = 100;
        for(i=0;i<m;++i) {
            md = min(md, dist[j][chosen[i]]);
        }
        ret += md;
    }
    return ret;
}

static void bf(int step, int base) {
    if (m-step == t-base) {
        while(step<m) {
            chosen[step++]=base++;
        }
    }
    if(step==m) {
        ans = min(ans, citychickendist());
        return;
    }
    /*else if (m-step == t-base) {
        for(int i=step;i<m;++i) {
            chosen[i]=base++;
        }
        ans = min(ans, citychickendist());
        return;
    }*/
    chosen[step]=base;
    bf(step+1, base+1);
    bf(step, base+1);
}

int main() {
    vector<coord> houses, chickens;
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    int i, j, a;
    for(i=0;i<n;++i) for(j=0;j<n;++j) {
        cin >> a;
        if(a) {
            if(a==1) {
                houses.push_back({i, j});
            }
            else chickens.push_back({i, j});
        }
    }
    t = chickens.size();
    dist.resize(s = houses.size());
    for(j=0;j<s;++j) for(i=0;i<t;++i) dist[j].push_back(d(houses[j], chickens[i]));
    bf(0, 0);
    cout << ans;
    return 0;
}