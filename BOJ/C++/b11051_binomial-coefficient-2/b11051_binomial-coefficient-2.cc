#include <iostream>
using namespace std;
int arr[1010][1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for(int i=0, j;i<=n;++i) for(j=0;j<=i;++j) arr[i][j] = (j==0 || j==i)?1:(arr[i-1][j-1] + arr[i-1][j])%10007;
    cout << arr[n][k];
    return 0;
}