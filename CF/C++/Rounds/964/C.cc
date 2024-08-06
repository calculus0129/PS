#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, s, m, avail; cin >> n >> s >> m;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;++i) {
            cin >> arr[i].first >> arr[i].second;
        }
        avail = 0;
        bool r = false;
        for(int i=0;i<n && !r;++i) {
            if(arr[i].first - avail >= s) r = true;
            avail = arr[i].second;
        }
        if(m - avail >= s) r = true;
        cout << (r?"YES\n":"NO\n");
    }

    return 0;
}