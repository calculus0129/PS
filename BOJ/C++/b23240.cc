#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=LLONG_MAX;
int m, r[26];
char col[26];
ll sums[26][2], dp[26][4];

// sums[i][j]:
// 맨 위 0~i-1가지 반지름의 모든 디스크를 마지막 디스크만 j,
// 나머지는 다 0(안 뒤집힘)이 되도록 하는 최소한으로 움직이는 횟수.

// dp[i][j]:
// 1~i-3번째 디스크가 색깔 조건을 만족한다는 가정하에,
// i-2번째 disk가 j>>1, i-1번째 disk가 j&1이 되도록
// 움직이는 최소 이동횟수.

pair<ll,ll> slns(int n) {
    ll d[4];
    for(int i=0;i<4;++i) {
        d[i] = (
            i<2 && col[n-2]=='R' || i>=2 && col[n-2]=='B'
        ? INF : dp[n][i]);
    }
    return make_pair(min(d[0], d[2]), min(d[1], d[3]));
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m;
    for(int i=0;i<m;++i) cin >> col[i] >> r[i];

    // sums 배열들을 먼저 초기화.
    sums[1][0] = (r[0]<<1)-1;
    sums[1][1] = r[0];
    for(int i=2;i<=m;++i) {
        sums[i][0] = (sums[i-1][1] + r[i-1] << 1) + sums[i-1][0];
        sums[i][1] = (sums[i-1][1]<<1) + r[i-1];
    }

    // 그 다음, dp 배열을 채운다.
    dp[2][0] = sums[2][0];
    dp[2][1] = sums[2][1];
    dp[2][2] = 3*r[0] + 2*r[1];
    dp[2][3] = 3*r[0] + 1*r[1] - 1;

    for(int i=2;i<m;++i) {
        auto [p0, p1] = slns(i);
        // cout << "p0, p1 for i=" << i-1 << " is " << p0 << ", " << p1 << '\n';
        dp[i+1][0] = (sums[i][1] + r[i]<<1) + p0;
        dp[i+1][2] = (sums[i][1] + r[i]<<1) + p1;
        dp[i+1][1] = min(sums[i][1] + p1, sums[i][0] + p0) + r[i];
        dp[i+1][3] = min(sums[i][1] + p0, sums[i][0] + p1) + r[i];
    }

    ll d[4];
    for(int i=0;i<4;++i) {
        d[i] = (
            i<2 && col[m-2]=='R' ||
            i>=2 && col[m-2]=='B' ||
            !(i&1) && col[m-1]=='R' ||
            (i&1) && col[m-1]=='B'
        ? INF : dp[m][i]);
    }

    // for(int i=0;i<4;++i) cout << dp[m][i] << ' ';
    // cout << '\n';

    cout << *min_element(d, d+4);

    return 0;
}