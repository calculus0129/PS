#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define SQR(x) (x)*(x)
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
typedef pair<int, int> pii;
int s[1001], r[1001], setarr[1001];
pii pos[1001];
double dists[1001][1001];
vector<pii> edges;
int n;

double dist(int a, int b) {
    double d = sqrt( SQR(pos[b].X-pos[a].X)+SQR(pos[b].Y-pos[a].Y) );
    if(d<=r[a]+r[b]) return 0;
    if(r[a]>r[b]) swap(a, b);
    double alpha = asin((r[b]-r[a])/d);
    return 2*sqrt(SQR(pos[b].X-pos[a].X)+SQR(pos[b].Y-pos[a].Y)-SQR(r[b]-r[a]))+r[a]*(M_PI-2*alpha)+r[b]*(M_PI+2*alpha);
}

void addEdges() {
    for(int i=0, j;i<n;++i) for(j=i+1;j<n;++j) {
        edges.push_back({i, j});
    }
}

void findDists() {
    for(int i=0, j;i<n;++i) for(j=i+1;j<n;++j) {
        dists[i][j] = dist(i, j);
    }
}

void sortEdges() {
    sort(ALL(edges), [](const pii &a, const pii &b) -> bool {
        return dists[a.X][a.Y] < dists[b.X][b.Y];
    });
}

void initSets() {
    for(int i=0;i<n;++i) setarr[i] = i;
}

void init() {
    addEdges();
    findDists();
    sortEdges();
    initSets();
}

int find(int a) {
    if(setarr[a] == a) return a;
    return setarr[a] = find(setarr[a]);
}

bool unionize(int a, int b) {
    int fa = find(a), fb = find(b);
    if(fa == fb) return false;
    setarr[fa] = setarr[fb] = min(fa, fb); // setarr[a] = setarr[b] = min(fa, fb);로 했다가 틀림;;
    return true;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    edges.reserve(n*n>>1);
    for(int i=0;i<n;++i) {
        cin >> pos[i].X >> pos[i].Y >> r[i];
    }
    init();
    double ans = 0;
    for(const pii &e: edges) if(unionize(e.X, e.Y)) {
        ans += dists[e.X][e.Y];
    }
    cout.precision(8);
    cout << ans;

    return 0;
}