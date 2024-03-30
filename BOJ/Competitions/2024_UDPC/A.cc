#include <bits/stdc++.h>
using namespace std;
int c[3], d[3], h;
int work() {
    int ret = 0;
    for(int i=0;i<3;++i) if(ret % d[i] == 0) {
        h -= c[i];
    }
    while(h>0) {
        ++ret;
        for(int i=0;i<3;++i) if(ret % d[i] == 0) {
            h -= c[i];
        }
    }
    return ret;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    for(int i=0;i<3;++i) {
        cin >> d[i] >> c[i];
    }
    cin >> h;
    cout << work();
    return 0;
}