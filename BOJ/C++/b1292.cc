#include <bits/stdc++.h>
using namespace std;

vector<int> arr(int n) {
    int ret = 1;
    while(n>ret) {
        n -= ret++;
    }
    return {ret, n};
}

int main() {
    int m, n, ax, ay, bx, by;
    cin >> m >> n;
    vector<int> a = arr(m), b = arr(n);

    ax = a[0];
    ay = a[1];
    bx = b[0];
    by = b[1];
    if(ax == bx) {
        cout << bx * (by - ay + 1);
    } else {
        int ans = ax * (ax-ay+1) + bx * by;
        for(int i=ax+1;i<bx;++i) {
            ans += i * i;
        }
        cout << ans;
    }
    return 0;
}