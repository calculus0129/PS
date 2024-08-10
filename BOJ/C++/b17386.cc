#include <bits/stdc++.h>
using namespace std;
int n;

struct Point {
    double x, y;
    Point operator+(const Point &p) const {
        return Point({x+p.x, y+p.y});
    }
    Point operator-(const Point &p) const {
        return Point({x-p.x, y-p.y});
    }
    double operator/(const Point &p) const {
        return x*p.y-y*p.x;
    }
};

// linear: 0, ccw: 1, cw: 2
int ori(const Point &a, const Point &b, const Point &c) {
    double q = (b-a)/(c-b);
    return q==0?0:q>0?1:2;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    Point a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cin >> b1.x >> b1.y >> b2.x >> b2.y;
    int o = ori(a1, b1, a2);
    cout << (o == ori(b1, a2, b2) && o == ori(a2, b2, a1) && o == ori(b2, a1, b1));
    return 0;
}