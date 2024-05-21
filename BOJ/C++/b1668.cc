#include <bits/stdc++.h>
using namespace std;
int arr[51];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> arr[i];
    int l=0, r=0, x;
    x=0;
    for(int i=0;i<n;++i) {
        if(arr[i]>x) {
            x=arr[i];
            ++l;
        }
    }
    x=0;
    for(int i=n-1;i>=0;--i) {
        if(arr[i]>x) {
            x=arr[i];
            ++r;
        }
    }
    cout << l << '\n' << r;
    
    return 0;
}