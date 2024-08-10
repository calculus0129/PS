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
    double operator*(const Point &p) const {
        return x*p.x+y*p.y;
    }
};

// linear: 0, ccw: 1, cw: -1
int ori(const Point &a, const Point &b, const Point &c) {
    double q = (b-a)/(c-b);
    return q>0?1:q<0?-1:0;
}

bool intersects(Point a1, Point a2, Point b1, Point b2) {
    int o1 = ori(a1, a2, b1);
    int o2 = ori(a1, a2, b2);
    int o3 = ori(b1, b2, a1);
    int o4 = ori(b1, b2, a2);
    if(o1 == o2 || o3 == o4) {
        if(o1 && o1 == o2 || o3 && o3 == o4) return false;
        return (b1-a1)*(b2-a1)<=0 || (b1-a2)*(b2-a2)<=0 || (a1-b1)*(a2-b1)<=0 || (a1-b2)*(a2-b2)<=0;
    }
    return true;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    Point a1, a2, b1, b2;
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    cin >> b1.x >> b1.y >> b2.x >> b2.y;
    cout << intersects(a1, a2, b1, b2);
    return 0;
}