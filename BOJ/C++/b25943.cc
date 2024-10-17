#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, w=0; cin >> n;
    while(n--) {
        int a; cin >> a;
        w = abs(a-w);
    }
    int arr[] = {100, 50, 20, 10, 5, 2, 1};
    int i=0, cnt=0;
    while(w) {
        cnt += w / arr[i];
        w %= arr[i++];
    }
    cout << cnt;
    return 0;
}