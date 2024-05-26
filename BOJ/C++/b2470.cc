#include <bits/stdc++.h>
using namespace std;
int arr[101010];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(arr, arr+n);
    int i=0,j=n-1,dist=INT_MAX, s, ai, aj;
    while(i<j) {
        s = arr[i]+arr[j];
        if(dist>abs(s)) {
            ai=i;
            aj=j;
            dist=abs(s);
        }
        if(s==0) {
            break;
        }
        if(s>0) {
            --j;
        }
        else {
            ++i;
        }
    }
    cout << arr[ai] << ' ' << arr[aj];

    return 0;
}