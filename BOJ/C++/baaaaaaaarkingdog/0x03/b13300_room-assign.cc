#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, n, k, i, ans=0; cin >> n >> k;
    int arr[7][2];
    for(i=0;i<7;++i) fill(arr[i], arr[i]+2, 0);
    while(n--) {
        cin >> a >> b;
        arr[b][a]++;
    }
    for(i=1;i<7;++i) {
        ans+=(arr[i][0]/k)+(arr[i][0]%k!=0);
        ans+=(arr[i][1]/k)+(arr[i][1]%k!=0);
    }
    cout << ans;
    return 0;
}