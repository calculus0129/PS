#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;

vector<int> arr;

int see(int x) {
    // cout << "see " << x << endl;
    int ret = 1, dist, pos;
    dist=1,pos=x;
    auto it=lower_bound(ALL(arr), x),s=lower_bound(ALL(arr), x);
    for(auto e=arr.begin(),prit = arr.begin();it!=e && it!=prit;dist++) {
        prit=it;
        it = lower_bound(ALL(arr), pos-dist);
        // cout << "pos " << pos << " dist " << dist << " it " << *it << endl;
        pos = *it;
    }
    ret += s-it;
    it = s;
    dist=1,pos=x;
    for(auto e = arr.end() - 1,prit=arr.end() - 1;it!=e && it!=prit;dist++) {
        prit=it;
        it = upper_bound(ALL(arr), pos+dist) - 1;
        // cout << "pos " << pos << " dist " << dist << " it " << *it << endl;
        pos = *it;
    }
    ret += it-s;
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    arr.assign(n, 0);
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    sort(ALL(arr));
    int ans = 0;
    for(int i=0;i<n;++i) {
        ans = max(ans, see(arr[i]));
    }
    cout << ans;

    return 0;
}