#include <bits/stdc++.h>
#define SQR(x) (x)*(x)
#define ALL(x) x.begin(), x.end()
#define x first
#define y second
using namespace std;
using ll = long double;
using Point = pair<ll, ll>;
Point operator + (Point p1, Point p2) { return {p1.x + p2.x, p1.y + p2.y}; }
Point operator - (Point p1, Point p2){ return {p1.x - p2.x, p1.y - p2.y}; }
ll operator * (Point p1, Point p2){ return p1.x * p2.x + p1.y * p2.y; } // 내적
ll operator / (Point p1, Point p2){ return p1.x * p2.y - p2.x * p1.y; } // 외적
int Sign(ll v){return (v>0)-(v<0);}// 양수면 +1, 음수면 -1,0이면 0 반환
ll Dist(Point p1, Point p2){return (p2-p1)*(p2-p1);} //두 점 거리 제곱
ll SignedArea(Point p1, Point p2, Point p3){ return (p2 - p1) / (p3 - p1); }
int CCW(Point p1, Point p2, Point p3){ return Sign(SignedArea(p1, p2, p3)); }

int n;
vector<Point> points;
int radii[1001];
struct Edge {
    int a, b;
    ll w;
};
vector<Edge> edges;

ll dist(int a, int b) {
    if(Dist(points[a], points[b])<=SQR(radii[a]+radii[b])) return 0;
    if(radii[a]>radii[b]) swap(a, b);
    ll dsq = Dist(points[a], points[b]);
    ll alpha = asin((radii[b]-radii[a])/sqrt(dsq));
    return 2*sqrt(dsq-SQR(radii[b]-radii[a]))+radii[a]*(M_PI-2*alpha) + radii[b]*(M_PI+2*alpha);
}

void makeGraph() {
    for(int i=0,j;i<n;++i) for(j=i+1;j<n;++j) {
        edges.push_back({i, j, dist(i, j)});
    }
    sort(ALL(edges), [](const Edge &a, const Edge &b) -> bool{
        return a.w<b.w;
    });
}

int S[1001];

int find(int a) {
    if(S[a] == a) return a;
    return S[a] = find(S[a]);
}

// unionize the two sets that contain a and b.
// Return true if they were not equal, false if they were equal.
bool unionize(int a, int b) {
    int sa = find(a), sb = find(b);
    if(sa == sb) return false;
    S[sa] = sb;
    return true;
}

ll kruskal() {
    ll ret = 0;
    for(int i=0;i<n;++i) S[i] = i;
    for(Edge e: edges) if(unionize(e.a, e.b)) ret += e.w;
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    points.resize(n);
    for(int i=0;i<n;++i) {
        cin >> points[i].x >> points[i].y;
        cin >> radii[i];
    }
    makeGraph();
    cout << setprecision(6) << scientific << kruskal();

    return 0;
}