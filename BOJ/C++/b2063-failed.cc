#include <bits/stdc++.h>
using namespace std;
double arr[31];
double harr[31];
int n;
bool search(int idx, double sum, bool selected=false) {
    if(sum == 0 && selected) return true;
    int nidx;
    while(--idx>=0) {
        nidx = upper_bound(arr, arr+idx, sum-harr[idx])-arr;
        if(search(nidx, sum-harr[idx], selected)) return true;
        nidx = upper_bound(arr, arr+idx, sum-arr[idx])-arr;
        if(search(nidx, sum-arr[idx], true)) return true;
    }
    return false;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int k; cin >> k;
    int idx;
    double s;
    while(k--) {
        cin >> n;
        s=0.0;
        for(int i=0;i<n;++i) {
            cin >> arr[i];
            harr[i] = arr[i]/2;
            s += arr[i];
        }
        sort(arr, arr+n);
        idx = upper_bound(arr, arr+n, s/2)-arr;
        cout << (search(idx, s/2)? "YES\n": "NO\n");
    }
    return 0;
}