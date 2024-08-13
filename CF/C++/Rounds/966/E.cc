#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int m, n, k; cin >> m >> n >> k;
        vector<vector<int>> arr(m+2, vector<int>(n+2));
        for(int i=1,j;i+k<=m+1;++i) for(j=1;j+k<=n+1;++j) {
            arr[i][j]++;
            arr[i][j+k]--;
            arr[i+k][j]--;
            arr[i+k][j+k]++;
        }
        for(int i=1,j;i<=m;++i) {
            for(j=1;j<=n;++j) {
                arr[i][j] += arr[i][j-1];
            }
        }
        for(int j=1,i;j<=n;++j) {
            for(i=1;i<=m;++i) {
                arr[i][j] += arr[i-1][j];
            }
        }
        priority_queue<int> pq;
        priority_queue<ll> pq2;
        for(int i=1,j;i<=m;++i) for(j=1;j<=n;++j) pq.push(arr[i][j]);
        ll ans = 0LL;
        cin >> n;
        for(int i=0,h;i<n;++i) {
            cin >> h;
            pq2.push(h);
        }
        for(int i=0;i<n;++i) {
            ans += pq.top() * pq2.top();
            pq.pop(); pq2.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}