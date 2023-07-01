#include <bits/stdc++.h>
using namespace std;
int cost[1010][4], D[1010][4];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    cin >> n;
    for(i=1;i<=n;++i) for(j=1;j<=3;++j) cin >> cost[i][j];
    // D[i][j]: 각 집을 색 j로 칠할 때 1번부터 i번 집을 칠하는데 드는 최소 비용
    // D[i][j] = cost[i][j] + min(D[i-1][...]).
    memcpy(D, cost, sizeof(cost));
    for(i=1;i<=n;++i) {
        D[i][1] += min(D[i-1][2], D[i-1][3]);
        D[i][2] += min(D[i-1][3], D[i-1][1]);
        D[i][3] += min(D[i-1][1], D[i-1][2]);
    }
    int* p = &D[n][0];
    cout << *min_element(p+1, p+4);
    return 0;
}