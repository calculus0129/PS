#include <bits/stdc++.h>
using namespace std;
unordered_map<vector<bool>, int> mp;
vector<vector<bool>> arr;
int ans;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    arr.resize(m, vector<bool>(n));
    for(int i=0,j;i<m;++i) {
        string s;
        cin >> s;
        for(j=0;j<n;++j) {
            arr[i][j] = s[j] == '1';
        }
    }
    int k; cin >> k;
    for(int i=0;i<m;++i) {
        int cnt = 0;
        for(int j=0;j<n;++j) if(arr[i][j] == false) ++cnt;
        if(cnt&1^k&1 || cnt>k) continue;
        if(++mp[arr[i]] > ans) ans = mp[arr[i]];
    }
    cout << ans;

    return 0;
}