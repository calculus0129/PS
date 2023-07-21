#include <bits/stdc++.h>
using namespace std;
int n;
int water_bottle_num(int x) {
    int ret = 0;
    for(int i=0, j, a, cnt;i<=24;++i) {
        a=-1;
        cnt = 0;
        for(j=0;j<=24 && x>>j;++j) {
            if(a<0 && x>>j & 1) {
                a = j;
            }
            cnt += x>>j & 1;
        }
        if(cnt<=n) break;
        ret += 1<<a;
        x += 1<<a;
    }
    return ret;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k;
    cin >> k >> n;
    cout << water_bottle_num(k);
    return 0;
}