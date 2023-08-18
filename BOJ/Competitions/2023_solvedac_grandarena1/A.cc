#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n=5, a;
    while(n--) {
        cin >> a;
        arr[a]++;
    }
    for(n=0;n<10;++n) if(arr[n]&1) {
        cout << n;
        break;
    }
    return 0;
}