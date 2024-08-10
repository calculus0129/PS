#include <bits/stdc++.h>
#define ADD(x,y) ((x+y)%8)
using namespace std;
int arr[8], inp[9], ans;
bool chosen[9];
struct vec {
	double x, y;
	vec operator+(const vec &v) const {
		return vec({x+v.x, y+v.y});
	}
	vec operator-(const vec &v) const {
		return vec({x-v.x, y-v.y});
	}
	vec operator*(double c) const {
		return vec({c*x, c*y});
	}
	double operator/(const vec &v) const {
		return x*v.y-y*v.x;
	}
};
vec polar(double r, double theta) {
	return vec({r*cos(theta), r*sin(theta)});
}

bool cw(const vec &a, const vec &b, const vec &c) {
	return (b-a)/(c-b)>0;
}

void check() {
	for(int i=0;i<8;++i) if(!cw(
				polar(arr[i], M_PI/4*i)
				, polar(arr[ADD(i,1)], M_PI/4*ADD(i,1))
				, polar(arr[ADD(i,2)], M_PI/4*ADD(i,2))
			)) return;
	++ans;
}

void dfs(int step = 0) {
	if(step == 8) {
		check();
		return;
	}
	for(int i=1;i<=8;++i) if(!chosen[i]) {
		chosen[i] = true;
		arr[step] = inp[i];
		dfs(step+1);
		chosen[i] = false;
	}
}

int main() 
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	for(int i=1;i<=8;++i) cin >> inp[i];
	dfs();
	cout << ans;
	return 0;
}
