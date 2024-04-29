#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii arr[1001];
int dp[1010][1010]; // dp[i][j]: 0-j째숙제까지 존재시 j째 숙제를 i째날까지 할 때 i째날까지 얻을 수 있는 최고 점수
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int d = INT_MIN;
    for(int i=0;i<n;++i) {
        cin >> arr[i].first >> arr[i].second;
        d = max(d, arr[i].first);
    }
    sort(arr, arr+n, [](const pii & r, const pii & l) {
        return r.first==l.first?r.second>l.second:r.first<l.first;
    });
    for(int i=1;i<=d;++i) dp[i][0] = arr[0].second;
    for(int j=1, i;j<n;++j) {
        for(i=1;i<=d;++i) {
            if(arr[j].first<i) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j-1]+arr[j].second);
            }
        }
    }
    // for(int i=0, j;i<=d;++i){
    //     for(j=0;j<n;++j) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    
    cout << dp[d][n-1];

    return 0;
}