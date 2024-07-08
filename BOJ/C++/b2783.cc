#include <bits/stdc++.h>
using namespace std;

struct frac {
    int numer, denomer;
    bool operator<(const frac &other) {
        return numer * other.denomer < other.numer * denomer;
    }
};

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, x, y;

    cin >> x >> y;
    cin >> n;
    for(int a, b, i=0;i<n;++i) {
        cin >> a >> b;
        if(frac{a, b}<frac{x, y}) {
            x=a;
            y=b;
        }
    }
    setprecision(2);
    cout << fixed << 1000 * x / (double)y;
    return 0;
}