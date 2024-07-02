#include <bits/stdc++.h>
using namespace std;
int n;
// bool cross[2501][2501];
typedef long long ll;
ll ans;

struct Point {
    long long x, y;
};

struct Segment {
    Point s, e;
    long long w;
};

map<Segment, int> bagmap;
Segment baggies[2501];

int orientation(Point p, Point q, Point r) {
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    return false; // Doesn't consider collinearity
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].s.x >> segments[i].s.y >> segments[i].e.x >> segments[i].e.y >> segments[i].w;
    }
    sort(segments.begin(), segments.end(), [](const Segment &a, const Segment &b) -> bool {
        return a.w<b.w;
    });

    long long totalWeight = 0;

    for (int i = 0; i < n; ++i) {
        totalWeight += segments[i].w;
        for (int j = i + 1; j < n; ++j) {
            if (doIntersect(segments[i].s, segments[i].e, segments[j].s, segments[j].e)) {
                totalWeight += segments[i].w;
            }
        }
    }

    cout << totalWeight << endl;
    return 0;
}

// struct vec {
//     ll x, y;
//     ll operator*(const vec &other) const {
//         return x*other.x+y*other.y;
//     }
//     vec operator-(const vec &other) const {
//         return vec{x-other.x, y-other.y};
//     }
// };

// int sign(ll a) {
//     if(a>0LL) return 1;
//     if(a<0LL) return -1;
//     return 0;
// }

// struct baggi {
//     vec s, e;
//     ll w;
//     bool operator<(baggi const & other) const {
//         return w<other.w;
//     }
//     vec orth() const {
//         return vec{s.y-e.y, e.x-s.x};
//     }
//     bool crossed(baggi const & other) const {
//         return sign(other.orth()*(s-other.s))*sign(other.orth()*(e-other.s))<=0;
//     }
// };
// map<baggi, int> bagmap;
// baggi baggis[2501];

// void input() {
//     cin >> n;
//     for(int i=0;i<n;++i) {
//         ll a, b, c, d, e;
//         cin >> a >> b >> c >> d >> e;
//         bagmap[baggis[i]={vec{a, b}, vec{c, d}, e}]=i;
//     }
// }

// // // get all the vector v and scalar c s.
// // void preprocess() {

// // }

// void fil() {
//     for(int i=0,j;i<n;++i) for(j=0;j<n;++j) if(i==j || baggis[i].crossed(baggis[j]) && baggis[j].crossed(baggis[i])) cross[i][j]=true;
// }

// void work() {
//     for(const auto &p: bagmap) {
//         int idx=p.second, gong=0;
//         for(int i=0;i<n;++i) if(cross[idx][i]) {
//             cross[idx][i]=cross[i][idx]=false;
//             gong++;
//         }
//         ans += gong*p.first.w;
//     }
// }

// int main() {
//     cin.tie(NULL); ios_base::sync_with_stdio(false);
//     input();
//     // preprocess();
//     fil();
//     work();
//     cout << ans;
//     return 0;
// }