#include <bits/stdc++.h>
using namespace std;
// MST on a metric space (node*, dist)
struct node {
    double x, y;
};

double dist(const node &a, const node &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

struct edge {
    node *a, *b;
    bool operator<(const edge &e) const {
        return dist(*a, *b)<dist(*e.a, *e.b);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, i=0, j, n;
    cin >> n;
    vector<node*> vertices(n);
    for(i=0;i<n;++i) vertices[i] = new node;
    i=0;
    while(i<n) cin >> vertices[i]->x >> vertices[i++]->y;

    vector<edge> edges;
    for(i=0;i<n;++i) for(j=i+1;j<n;++j) edges.push_back({vertices[i], vertices[j]});

    sort(edges.begin(), edges.end());
    /*for(i=0;i<edges.size();++i) {
        cout << '(' << edges[i].a->x << ',' << edges[i].a->y << \
        ") and (" << edges[i].b->x << ',' << edges[i].b->y << ')' << \
        " with metric " << dist(*edges[i].a, *edges[i].b) << endl;
    }*/

    // For Kruskal's Algorithm.
    map<node*,node*> s;
    for(i=0;i<n;++i) s.insert({vertices[i], vertices[i]});

    node *a, *b;
    int cnt=0;
    double cost=0, d;
    auto idx = edges.begin();
    while(cnt<n-1) {
        a = idx->a, b=idx++->b, d=dist(*a, *b);
        while(a!=s[a]) a = s[a];
        while(b!=s[b]) b = s[b];
        if(a == b) continue;
        cost+=d;
        ++cnt;
        s[a] = s[b] = max(a, b);
    }
    cout << fixed;
    cout.precision(2);
    cout << cost;
    return 0;
}

/*
입력:
6
4 1
5 8
2 1
8 4
2 9
1 4
정답: 18.32
오답: 20.42
*/

/* or...
#include <bits/stdc++.h>
using namespace std;
// MST on a metric space (node*, dist)
struct xy {
    double x, y;
};
typedef xy* node;

double dist(const node &a, const node &b) {
    return sqrt((a->x-b->x)*(a->x-b->x) + (a->y-b->y)*(a->y-b->y));
}

struct edge {
    node a, b;
    bool operator<(const edge &e) const {
        return dist(a, b)<dist(e.a, e.b);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, w, i=0, j, n;
    cin >> n;
    vector<node> vertices(n);
    for(i=0;i<n;++i) vertices[i] = new xy;
    i=0;
    while(i<n) cin >> vertices[i]->x >> vertices[i++]->y;

    vector<edge> edges(n*n);
    for(i=0;i<n;++i) for(j=0;j<n;++j) edges[i*n+j]={vertices[i], vertices[j]};

    sort(edges.begin(), edges.end());

    // For Kruskal's Algorithm.
    map<node,node> s;
    for(i=0;i<n;++i) s.insert({vertices[i], vertices[i]});

    node a, b;
    int cnt=0;
    double cost=0;
    auto idx = edges.begin();
    while(cnt<n-1) {
        a = idx->a, b=idx++->b;
        while(a!=s[a]) a = s[a];
        while(b!=s[b]) b = s[b];
        if(a == b) continue;
        cost+=dist(a, b);
        ++cnt;
        s[a] = s[b] = max(a, b);
    }
    cout << fixed;
    cout.precision(2);
    cout << cost;
    return 0;
}*/
