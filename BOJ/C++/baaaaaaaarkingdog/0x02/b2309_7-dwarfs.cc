#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[9], sum=-100, *p1=arr, *p2=arr+8;
    for(int i=0;i<9;++i) {
        cin >> arr[i];
        sum+=arr[i];
    }
    while(sum!=*p1+*p2) {
        if(sum<*p1+*p2) p2--;
        else p1++;
    }
    *p1=*p2=100;
    sort(arr, arr+9);
    for(int i=0;i<7;++i) cout << arr[i] << '\n';

    return 0;
}