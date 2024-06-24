#include <bits/stdc++.h>
using namespace std;
int arr[51][51];
// char carr[51][51];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    char c;
    for(int i=0,j;i<m;++i) for(j=0;j<n;++j) {
        cin >> c;
        arr[i][j] = c-'0';
    }
    int ans = 0;
    for(int i=0,j, x, a;i<m;++i) for(j=0;j<n;++j) {
        a = arr[i][j];
        for(x=min(m-1-i, n-1-j);x>ans;--x) {
            if(a == arr[x+i][x+j] && a == arr[i][x+j] && a == arr[x+i][j]) {
                ans = x;
                break;
            }
        }
    }

    cout << (ans+1)*(ans+1);

    return 0;
}