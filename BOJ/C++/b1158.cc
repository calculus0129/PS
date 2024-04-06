#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> arr;
int ans[5001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    arr.reserve(n);
    for(int i=1;i<=n;++i) {
        arr.push_back(i);
    }
    int i=0;
    for(int _=0;_<n;++_) {
        i = (i+k-1)%arr.size();
        ans[_]=arr[i];
        arr.erase(arr.begin()+i);
    }
    cout << '<';
    cout << ans[0];
    for(i=1;i<n;++i) cout << ", " << ans[i];
    cout << '>';
    
    return 0;
}