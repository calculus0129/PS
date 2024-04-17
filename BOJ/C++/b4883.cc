#include <bits/stdc++.h>
using namespace std;
int n, arr[101010][3];
void work() {
    arr[0][0] = INT_MAX;
    arr[0][2] += arr[0][1];
    for(int i=1;i<n;++i) {
        arr[i][0] += min(arr[i-1][0], arr[i-1][1]);
        arr[i][1] += min(min(arr[i][0], arr[i-1][0]), min(arr[i-1][1], arr[i-1][2]));
        arr[i][2] += min(arr[i][1], min(arr[i-1][1], arr[i-1][2]));
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t=0;
    cin >> n;
    while(n) {
        for(int i=0;i<n;++i) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }
        work();
        cout << ++t << ". " << arr[n-1][1] << '\n';
        cin >> n;
    }

    return 0;
}