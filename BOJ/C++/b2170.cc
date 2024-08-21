#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef pair<int,int> pi;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<pi> arr(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(ALL(arr), [](const pi &a, const pi &b) -> bool {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });
    int ans=0;
    for(int i=0, s, e;i<n;++i) {
        s = arr[i].first;
        e = arr[i].second;
        while(i<n-1 && arr[i+1].first <= e) {
            e = max(arr[++i].second, e);
        }
        ans += e-s;
    }
    cout << ans;
    return 0;
}