#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pi=pair<int,int>;
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<pi> arr;
    arr.reserve(300000);
    for(int i=0, s ,e;i<n;++i) {
        cin >> s >> e;
        if(e<s) arr.push_back({s, e});
    }
    sort(arr.begin(), arr.end(), [](const pi &a, const pi &b) -> bool {
        return a.X == b.X ? a.Y<b.Y : a.X>b.X;
    });
    n=arr.size();
    ll ans = m;
    for(int i=0,e,s;i<n;++i) {
        s = arr[i].X, e = arr[i].Y;
        while(i<n-1 && arr[i+1].X >= e) {
            e = min(e, arr[++i].Y);
        }
        ans += s-e<<1;
    }
    cout << ans;
    return 0;
}