#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int cnt[1000001]={}, arr[100001], x, i, ans=0;
    for(i=0;i<n;++i) cin >> arr[i];
    cin >> x;
    for(i=0;i<n;++i) {
        ans+=cnt[arr[i]];
        if(x-arr[i]>=0 && x-arr[i]<=1000000) cnt[x-arr[i]]++;
    }
    cout << ans;
    return 0;
}