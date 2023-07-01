#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[10], i, *p=arr;
    for(i=0;i<9;++i) {
        cin >> arr[i];
    }
    for(i=1;i<9;++i) if(*p<arr[i]) {
        p=arr+i;
    }
    cout << *p << '\n' << p-arr+1;
    return 0;
}