#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
int n;
vector<int> arr;
ll ans;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(ALL(arr), [](int a, int b) -> bool {
        return a>b;
    });
    for(int i=n-1;i>=0;--i) {
        ans += max(0, arr[i]-i);
    }
    cout << ans;
    
    return 0;
}