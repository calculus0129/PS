#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

void print(const vector<vector<int>> &arr) {
    for(const vector<int> &f: arr) {
        for(int v: f) cout << v << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int m, n;
    while(t--) {
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n));
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin >> arr[i][j];
        if(m>1) {
            vector<int> tmp(m);
            for(int i=0,j;i<n;++i) {
                for(j=0;j<m;++j) tmp[j] = arr[j][i];
                for(j=0;j<m;++j) arr[j][i] = tmp[(j+1)%m];
            }
            print(arr);
        }
        else if(n>1) {
            vector<int> tmp(n);
            for(int i=0,j;i<m;++i) {
                for(j=0;j<n;++j) tmp[j] = arr[i][j];
                for(j=0;j<n;++j) arr[i][j] = tmp[(j+1)%n];
            }
            print(arr);
        }
        else cout << "-1\n";
    }
    return 0;
}