#include <bits/stdc++.h>
#define SQR(a) ((a)*(a))
#define DIST(a,b,c,d) sqrt(SQR(c-a)+SQR(d-b))
#define ANGLE(a,b,c) acos((SQR(b)+SQR(c)-SQR(a))/(2*(b)*(c)))
#define AREA(r,c) ((c)-sin(c)*cos(c))*SQR(r)

using namespace std;
int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double dist = DIST(x1, y1, x2, y2);
	cout << fixed << setprecision(3);
	if(dist>=r1+r2) {
		cout << 0.0f;
	} else if(dist<=fabs(r1-r2)) {
		cout << M_PI*SQR(min(r1,r2));
	} else {
		double alpha = ANGLE(r2,r1,dist);
		double beta = ANGLE(r1,r2,dist);
		cout << AREA(r1,alpha) + AREA(r2,beta);
	}
	return 0;
}
