#include <bits/stdc++.h>
using namespace std;
int arr[101010][3];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    arr[0][0]=1;
    for(int i=1, j;i<=n;++i) {
        arr[i][0] = (arr[i-1][0]+arr[i-1][1]+arr[i-1][2]) % 9901;
        arr[i][1] = (arr[i-1][0] + arr[i-1][2]) % 9901;
        arr[i][2] = (arr[i-1][0] + arr[i-1][1]) % 9901;
    }
    cout << (arr[n][0] + arr[n][1] + arr[n][2]) % 9901;
    return 0;
}