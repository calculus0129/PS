// https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)
#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
vector<int> arr, sarr, usarr;
int mp[1000100];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    arr.resize(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    sarr = arr;
    sort(ALL(sarr));
    usarr = sarr;
    usarr.erase(unique(ALL(usarr)), usarr.end());
    for(int i=0,j,s,m=usarr.size();i<m;++i) {
        j = usarr[i];
        s=upper_bound(ALL(sarr), j) - lower_bound(ALL(sarr), j);
        while(j<=1000000) {
            mp[j]+=s;
            j += usarr[i];
        }
    }
    for(int a: arr) {
        cout << mp[a]-1 << '\n';
    }
    return 0;
}