#include <bits/stdc++.h>
using namespace std;
int m, n, k, num;
char ans[500][500], arr[501][501];

void work() {
    int i, j, ii=m/k, jj=n/k, t;
    int tmp[26];
    for(i=0;i<k;++i) for(j=0;j<k;++j) {
        for(t=0;t<26;++t) tmp[t]=0;
        for(ii = i ; ii < m ; ii += k) for(jj = j ; jj < n ; jj += k) ++tmp[arr[ii][jj]-'A'];
        ans[i][j] = 'A'+max_element(tmp, tmp+26)-tmp;
        num+=m*n/k/k-*max_element(tmp, tmp+26);
    }
}

int main() {
    int i, j;
    char c;
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n >> k;
    for(i=0;i<m;++i) for(j=0;j<n;++j) cin >> arr[i][j];
    work();
    for(i=0;i<m;++i) for(j=0;j<n;++j) ans[i][j] = ans[i%k][j%k];
    cout << num << '\n';
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) cout << ans[i][j];
        cout << '\n';
    }

    return 0;
}