#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    vector<ll> arr;
    arr.reserve(101010);
    int idx=0, nidx;
    while(t--) {
        arr.clear();
        cin >> n;
        arr.resize(n);
        for(int i=0;i<n;++i) cin >> arr[i];
        sort(arr.begin(), arr.end());
        idx=0;
        bool r = false;
        while(idx<=(n>>1)) {
            nidx = upper_bound(arr.begin()+idx, arr.end(), arr[idx]) - arr.begin();
            if(nidx - idx > (n>>1)) {
                cout << arr[idx] << '\n';
                r = true;
                break;
            }
            idx = nidx;
        }
        if(!r) {
            cout << "SYJKGW\n";
        }
    }
    
    return 0;
}