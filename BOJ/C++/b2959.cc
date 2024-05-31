#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int arr[4]; for(int i=0;i<4;++i) cin >> arr[i];
    sort(arr, arr+4);
    cout << arr[2] * arr[0];
    return 0;
}