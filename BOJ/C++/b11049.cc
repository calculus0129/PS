#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, r[501]={0,}, D[501][501]={0,};
    
    cin >> n; cin >> r[0];
    for(int i=1, a;i<n;++i) {
        cin >> r[i] >> a;
    }
    cin >> r[n];

    for(int d=1, j,i, k;d<n;++d) {
        for(i=0;i<n-d;++i) {
            j = i + d;
            D[i][j] = D[i][i] + D[i+1][j] + r[i]*r[i+1]*r[j+1];
            for(k=i+1;k<j;k++) {
                D[i][j] = min(D[i][j], D[i][k] + D[k+1][j] + r[i]*r[j+1]*r[k+1]);
            }
        }
    }
    cout << D[0][n-1];
    
    return 0;
}