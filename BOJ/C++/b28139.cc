#include <bits/stdc++.h>
#define SQR(x) (x)*(x)
using namespace std;

struct coord {
    double x, y;
};
coord coords[5010];

double dist(const coord &a, const coord &b) {
    return sqrt(SQR(b.x-a.x)+SQR(b.y-a.y));
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;++i) cin >> coords[i].x >> coords[i].y;
    double ans = 0;
    for(int i=0,j;i<n-1;++i) for(j=i+1;j<n;++j) ans += dist(coords[i], coords[j]) * 2 / n;
    cout << showpoint << setprecision(7) << ans;

    return 0;
}