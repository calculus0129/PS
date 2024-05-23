#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int brr[1001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, sum=0;
    cin >> n;
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0;i<n;++i) sum += arr[i];
    sum>>=1;
    for(int i=0;i<n;i+=2) {
        sum -= arr[i];
    }
    brr[0] = -sum;
    for(int i=1;i<n;++i) {
        brr[i] = arr[i-1]-brr[i-1];
    }
    for(int i=0;i<n;++i) {
        cout << brr[i] << '\n';
    }

    return 0;
}