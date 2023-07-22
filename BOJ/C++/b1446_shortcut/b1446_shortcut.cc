#include <bits/stdc++.h>
using namespace std;
int shortcuts[13][3], arr[10101];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d, dist, i, ndist;
    cin >> n >> d;
    for(i=1;i<=n;++i) cin >> shortcuts[i][0] >> shortcuts[i][1] >> shortcuts[i][2];
    //for(dist=1;dist<=d;++dist) arr[dist] = dist;
    for(dist=0;dist<=d;++dist) {
        for(i=1;i<=n;++i) if(shortcuts[i][1] == dist) {
            ndist = arr[shortcuts[i][0]] + shortcuts[i][2];
            if(ndist < arr[dist]) arr[dist] = ndist;
        }
        arr[dist+1] = arr[dist]+1;
    }
    cout << arr[d];
    return 0;
}