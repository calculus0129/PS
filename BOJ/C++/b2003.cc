#include <bits/stdc++.h>
using namespace std;
int arr[10101], m, n;
int main() {
    cin >> n >> m;
    int i, j;
    for(i=0;i<n;++i) cin >> arr[i];
    int sum = 0, ans = 0;
    i=0, j=0;
    while(j<n) {
        if(sum<m) sum += arr[j++];
        else {
            if(sum==m) ++ans;
            sum -= arr[i++];
        }
    }
    while(sum>m) {
        sum -= arr[i++];
    }
    if(sum==m) ++ans;

    cout << ans;

    return 0;
}