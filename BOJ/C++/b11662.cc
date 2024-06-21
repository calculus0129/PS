#include <bits/stdc++.h>
using namespace std;
typedef double ld;

struct vec {
    ld x, y;
    vec operator*(ld d) const {
        return vec({d*x, d*y});
    }
    vec operator+(const vec &other) const {
        return vec({x+other.x, y+other.y});
    }
    vec operator-(const vec &other) const {
        return vec({x-other.x, y-other.y});
    }
    ld operator*(const vec &other) const {
        return x*other.x + y*other.y;
    }
    ld magn() const {
        return sqrt(x*x+y*y);
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    vec a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    vec beta = c-a, alpha = d-b-(c-a);
    ld t = 0.0f;
    if(alpha.magn() != 0.0f) {
        t = -(alpha*beta)/(alpha*alpha);
        if(t>=1) t = 1.0f;
        else if(t<=0) t = 0.0f;
    }
    cout.precision(7);
    cout << ((alpha*t)+beta).magn();

    return 0;
}