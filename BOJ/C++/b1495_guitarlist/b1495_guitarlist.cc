#include <bits/stdc++.h>
using namespace std;
bool arr[51][1010];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s, m, i=1;
    cin >> n >> s >> m;
    arr[0][s] = 1;
    for(int j, a;i<=n;++i) {
        cin >> a;
        for(j=0;j<=m;++j) if(arr[i-1][j]) {
            if(j+a >= 0 && j+a <= m) arr[i][j+a] = 1;
            if(j-a >= 0 && j-a <= m) arr[i][j-a] = 1;
        }
    }
    for(i=m;i>=0 && !arr[n][i];i--);
    cout << i;
    
    return 0;
}