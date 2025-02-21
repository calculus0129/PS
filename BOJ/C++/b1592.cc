#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m, l, x=0, cnt=0;
    cin >> n >> m >> l;
    vector<int> arr(n);
    while(arr[x] < m-1) {
        ++arr[x];
        if(arr[x]&2) x=(x+(n-l))%n;
        else x=(x+l)%n;
        ++cnt;
    }
    cout << cnt;

    return 0;
}