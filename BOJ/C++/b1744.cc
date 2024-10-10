#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(ALL(arr));
    int l = upper_bound(ALL(arr), 1) - lower_bound(ALL(arr), 1);
    if(l) {
        arr.erase(lower_bound(ALL(arr), 1), upper_bound(ALL(arr), 1));
        n -= l;
    }
    bool hasZero = lower_bound(ALL(arr), 0) != upper_bound(ALL(arr), 0);
    int lend = lower_bound(ALL(arr), 0) - arr.begin(), rend = upper_bound(ALL(arr), 0) - arr.begin();
    int ans = l;
    for (int i = 0; i < lend; i += 2) {
        if (i+1 < lend) ans += arr[i] * arr[i+1];
        else if(!hasZero) ans += arr[i];
    }
    for(int i = n-1; i >= rend; i -= 2) {
        if (i-1 >= rend) ans += arr[i] * arr[i-1];
        else ans += arr[i];
    }
    cout << ans;

    return 0;
}