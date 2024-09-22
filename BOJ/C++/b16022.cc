#include <bits/stdc++.h>
using namespace std;
int pos[101], arr[101];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> pos[i];
    sort(pos, pos+n);
    for(int i=1,dist;i<n;++i) {
        dist = pos[i] - pos[i-1];
        arr[i-1] += dist;
        arr[i] += dist;
    }
    cout << fixed << setprecision(1);
    cout << 0.5 * *min_element(arr+1, arr+n-1);
    return 0;
}