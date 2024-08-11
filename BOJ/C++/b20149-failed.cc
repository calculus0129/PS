#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;
	Point operator+(const Point &p) const {
		return Point({x+p.x, y+p.y});
	}

	Point operator-(const Point &p) const {
		return Point({x-p.x, y-p.y});
	}

	double operator*(const Point &p) const {
		return x*p.x+y*p.y;
	}

	double operator/(const Point &p) const {
		return x*p.y-y*p.x;
	}

	bool operator==(const Point &p) const {
		return x == p.x && y == p.y;
	}
};

bool between(const pair<Point,Point> &l, const Point &tgt) {
	const double eps = 1e-10;
	return (tgt - l.first) * (tgt - l.second) < eps;
}

bool parallel(const pair<Point,Point> &l1, const pair<Point,Point> &l2) {
	return (l1.second.y - l1.first.y)*(l2.second.x-l2.first.x) == (l1.second.x - l1.first.x) * (l2.second.y - l2.first.y);
}

Point intersection(const pair<Point,Point> &l1, const pair<Point,Point> &l2) {
	double a = l1.second.y - l1.first.y;
	double b = l1.first.x - l1.second.x;
	double c = l2.second.y - l2.first.y;
	double d = l2.first.x - l2.second.x;
	double denom = Point({a, b})/Point({c, d});
	//if(denom == 0) return Point({M_PI, M_PI});
	double c1 = l1.first / l1.second;
	double c2 = l2.first / l2.second;
	double xnumer = d * c1 - b * c2;
	double ynumer = -c * c1 + a * c2;
	return Point({xnumer/denom, ynumer/denom});
}

ostream& operator<<(ostream &os, const Point &p) {
	os << p.x << ' ' << p.y;
	return os;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	pair<Point,Point> l1, l2;
	cin >> l1.first.x >> l1.first.y >> l1.second.x >> l1.second.y;
	cin >> l2.first.x >> l2.first.y >> l2.second.x >> l2.second.y;
	//assert(!(l1.first == l1.second || l2.first == l2.second));
	if(parallel(l1, l2)) {
		if(parallel(l1, {l1.first, l2.first})) {
			cout << ( between(l1, l2.first) || between(l1, l2.second) || between(l2, l1.first) || between(l2, l1.second));
			// excluding cases where two endpoints of a line segment equal.
			if(between(l1, l2.first) ^ between(l1, l2.second) && between(l2, l1.first) ^ between(l2, l1.second)) {
				if(l1.first == l2.first || l1.first == l2.second) cout << '\n' << l1.first;
				else if(l1.second == l2.first || l1.second == l2.second) cout << '\n' << l1.second;
			}
		} else {
			cout << 0;
		}
	} else {
		Point ntst = intersection(l1, l2);
		if(between(l1, ntst) && between(l2, ntst)) {
			cout << fixed << setprecision(10) << 1 << '\n' << ntst;
		} else {
			cout << 0;
		}
	}
	return 0;
}

