#include <bits/stdc++.h>
using namespace std;
struct E {
    int a, b, w;
};
bool cmp(const E &a, const E &b) {
    return a.w<b.w;
}
int main() {
    int m, n, D[101010], i=0, a, b, w;
    while(++i<=100000) D[i]=i;
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    vector<E> edges(n), mst;
    i=0;
    while(i<n) cin >> edges[i].a >> edges[i].b >> edges[i++].w;
    sort(edges.begin(), edges.end(), cmp);
    int cnt=0, cost=0;
    i=0;
    while(cnt<m-1) {
        a = edges[i].a, b = edges[i].b, w = edges[i++].w;
        while(a!=D[a]) a = D[a];
        while(b!=D[b]) b = D[b];
        if(a==b) continue;
        D[a]=D[b]=min(a, b);
        cnt++; cost+=w; mst.push_back(edges[i-1]);
    }
    cost-=mst.back().w;
    cout << cost;
    
    return 0;
}
/*
int main() {
    int m, n, a, b, w, D[101010], i=0;
    
    cin.tie(0)->sync_with_stdio(0);
    vector<E> edges, mst;
    cin >> m >> n;
    while(n--) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    i=0;
    sort(edges.begin(), edges.end(), cmp);
    int cost=0, cnt=0;
    while(cnt<m-1 && i<edges.size()) {
        a = edges[i].a, b = edges[i].b, w=edges[i++].w;
        while(a!=D[a]) a = D[a];
        while(b!=D[b]) b = D[b];
        if(a==b) continue;
        cost+=w; ++cnt; mst.push_back({a, b, w});
        D[a]=D[b]=min(a, b);
    }
    cost -= mst.back().w;
    cout << cost;

    return 0;
}*/