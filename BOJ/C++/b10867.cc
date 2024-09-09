#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(int a: arr) {
        cout << a << ' ';
    }
    return 0;
}