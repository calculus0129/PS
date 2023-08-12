#include <bits/stdc++.h>
using namespace std;

struct edge {
    int w, a, b;
};

bool cmp(const edge &a, const edge &b) {
    return a.w > b.w;
}

vector<int> setvec;

int par(int a) {
    int pa = setvec[a];
    if(a!=pa) {
        return setvec[a] = par(pa);
    } else {
        return a;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, e, a, b, c, cost = 0;
    cin >> n >> e;
    setvec.resize(n+1);
    for(int i=1;i<=n;++i) setvec[i] = i;

    priority_queue<edge, vector<edge>, bool(*)(const edge &, const edge &)> pq(cmp);
    while(e--) {
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }
    edge tmp;
    int pa, pb;
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        pa = par(a = tmp.a), pb = par(b = tmp.b), c = tmp.w;
        if(pa == pb) continue;
        cost += c;
        setvec[pa] = setvec[pb] = min(pa, pb);
    }

    cout << cost;

    return 0;
}