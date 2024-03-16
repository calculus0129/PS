#include <bits/stdc++.h>
using namespace std;

bool is_yoon(int y) {
    return (y&3==0)?(y%100==0?y%400==0:true):false;
}

class date {
public:
    int y, m, d;
    date(int y, int m, int d)
    : y(y), m{m}, d(d) {}
    bool operator<(date &other) {
        return y==other.y?(m==other.m?(d<other.d):m<other.m):y<other.y;
    }
    bool operator<=(date &other) {
        return (y == other.y && m == other.m && d == other.d) || this->operator<(other);
    }
    int dist(date &other) {
        for(int y = this->y; y<other.y; ++y) {
            
        }
    }
};
int main() {
    cin.tie(NULL)->sync_with_stdio(false);

    return 0;
}