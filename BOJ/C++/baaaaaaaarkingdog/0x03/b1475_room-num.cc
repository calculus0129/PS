#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int arr[10], num=0;
    fill(arr, arr+10, 0);
    int n, i;
    cin >> n;
    while(n) {
        arr[n%10]++;
        n/=10;
    }
    for(i=0;i<6;++i) if(num<arr[i]) num=arr[i];
    for(i=7;i<9;++i) if(num<arr[i]) num=arr[i];
    i=(arr[6]+arr[9]+1)/2;
    if(i>num) num=i;
    cout << num;

    return 0;
}