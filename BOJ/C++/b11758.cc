#include <bits/stdc++.h>
#define SGN(x) ((x)>0?1:(x)<0?-1:0)
using namespace std;
struct Vec {
	int x, y;
	Vec operator+(const Vec &other) const {
		return Vec({x+other.x, y+other.y});
	}
	Vec operator-(const Vec &other) const {
		return Vec({x-other.x, y-other.y});
	}
	int operator/(const Vec &other) const {
		return x*other.y - y*other.x;
	}
};
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	Vec arr[3];
	for(int i=0;i<3;++i) cin >> arr[i].x >> arr[i].y;
	cout << SGN((arr[1]-arr[0])/(arr[2]-arr[1]));
	return 0;
}
