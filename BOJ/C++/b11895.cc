#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> arr[i];
    int sum = 0;
    for(int i=0;i<n;++i) sum ^= arr[i];
    if(n<2 || sum) cout << 0;
    else {
        for(int i=0;i<n;++i) sum += arr[i];
        sum -= *min_element(arr, arr+n);
        cout << sum;
    }

    return 0;
}