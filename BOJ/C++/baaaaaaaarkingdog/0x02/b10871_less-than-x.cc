#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> arr(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }

    for(int i=0;i<n;++i) if(arr[i]<x) {
        cout << arr[i] << ' ';
    }

    return 0;
}