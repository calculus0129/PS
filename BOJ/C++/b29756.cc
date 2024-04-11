#include <bits/stdc++.h>
using namespace std;
// arr[i][j]: i번째 구간 이후 j만큼의 체력이 남았을 때 1~i번째 구간동안 노래를 통해 얻을 수 있는 최고 점수.
// arr[i][j] = {
// j<max(0, (h_i-k)) => arr[i-1][j]
// j>=max(0, (h_i-k)) => max(arr[i-1][j], arr[i][j-h[i]]+s[i])
// 
// }
int arr[1001][101];
bool visited[1001][101];
int n, k;
int s[1010], h[1010];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i=1;i<=n;++i) {
        cin >> s[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> h[i];
    }
    visited[0][100]=true;
    for(int i=1, j, a, b;i<=n;++i) {
        for(j=0;j<=100;++j) if(visited[i-1][j]) {
            visited[i][a=min(j+k, 100)] = true;
            arr[i][a] = max(arr[i-1][j], arr[i][a]);
            b = min(j+k, 100)-h[i];
            if(b>=0) {
                visited[i][b] = true;
                arr[i][b] = max(arr[i][b], arr[i-1][j]+s[i]);
            }
        }
    }
    cout << *max_element(arr[n], &arr[n][101]);

    return 0;
}