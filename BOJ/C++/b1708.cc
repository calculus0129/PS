#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;

struct Point {
    double x, y;
    Point operator-(const Point &other) const {
        return Point({x-other.x, y-other.y});
    }
    // The cross-product z-coordinate
    double operator*(const Point &other) const {
        return x*other.y-y*other.x;
    }
    double magn() const {
        return sqrt(x*x+y*y);
    }
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};
vector<Point> arr;
stack<Point> stk;

// returns the 'comparator' of the cross product of ab and bc is strictly positive.
// i.e. the two vectors are 'counterclockwise'.
// i.e. a->b->c is 'left'.
// or if the first two points are equivalent, return 1. (for my purpose. We can use this to general problem as well.)
int ccw(const Point &a, const Point &b, const Point &c) {
    return (b-a)*(c-b)>0 || a == b ? 1 : (b-a)*(c-b)==0?0:-1;
}

int n;
void init_sort() {
    auto tmp0 = min_element(ALL(arr), [](const Point &a, const Point &b) -> bool {
        return a.y==b.y ? a.x<b.x : a.y<b.y;
    });
    Point p0 = *tmp0;
    arr.erase(tmp0);
    sort(ALL(arr), [p0](const Point &a, const Point &b) -> bool {
        return ccw(p0, a, b)>0 || ccw(p0, a, b)==0 && (a-p0).magn()<(b-p0).magn();
    });
    arr.insert(arr.begin(), p0);
}

void work() {
    stk.push(arr[0]); // push one more thing 'for my purpose'
    stk.push(arr[0]);
    stk.push(arr[1]);
    for(int i=2;i<n;++i) {
        Point s1, s2;
        do {
            s1 = stk.top(); stk.pop(); s2 = stk.top();
        } while(ccw(s2, s1, arr[i])<=0); // alternatively 'for my purpose', we may put || stk.empty().
        stk.push(s1);
        stk.push(arr[i]);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i].x >> arr[i].y;
    }

    init_sort();
    // for(int i=0;i<n;++i) {
    //     cout << i << ": " << arr[i].x << ' ' << arr[i].y << '\n';
    // }
    work();
    cout << stk.size()-1; // consider the 'one-more pushed' initial element.

    return 0;
}