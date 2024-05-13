#include <bits/stdc++.h>
using namespace std;
int arr[10], ans[10], warr[10];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        warr[i] = i;
    }
    for(int i=0, j;i<n;++i) {
        ans[warr[arr[i]]] = i+1;
        for(j=arr[i];j<n;++j) warr[j] = warr[j+1];
    }

    for(int i=0;i<n;++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}