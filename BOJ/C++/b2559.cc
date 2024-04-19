#include <bits/stdc++.h>
using namespace std;
int arr[101010];
int n, k, ans, s;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int i;
    for(i=0;i<n;++i) cin >> arr[i];
    for(i=0;i<k;++i) s += arr[i];
    ans = s;
    while(i<n) {
        s += arr[i]-arr[i-k];
        if(s>ans) ans = s;
        ++i;
    }
    cout << ans;
    return 0;
}