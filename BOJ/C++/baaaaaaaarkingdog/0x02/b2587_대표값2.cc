#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    sort(arr, arr+5);
    cout << (arr[0]+arr[1]+arr[2]+arr[3]+arr[4])/5 \
     << '\n' << arr[2];
     return 0;
}