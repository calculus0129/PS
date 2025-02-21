#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int k; cin >> k;
    for(int i=0, n, gap=0;i<k;++i, gap=0) {
        cin >> n;
        vector<int> arr(n);
        for(int j=0;j<n;++j) cin >> arr[j];
        sort(ALL(arr));
        for(int j=1;j<n;++j) gap = max(gap, arr[j]-arr[j-1]);
        cout << "Class " << i+1 << '\n';
        cout << "Max" << ' ' << arr.back() << ", Min " << arr[0] << ", Largest gap " << gap << '\n';
    }
    return 0;
}