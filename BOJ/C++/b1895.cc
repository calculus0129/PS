#include <bits/stdc++.h>
using namespace std;
int r, c, arr[41][41], masked[39][39];

int mask(int x, int y) {
    vector<int> vec;
    for(int i=0,j;i<3;++i) for(j=0;j<3;++j) {
        vec.push_back(arr[x+i][y+j]);
    }
    sort(vec.begin(), vec.end());
    return masked[x][y] = vec[4];
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for(int i=0,j;i<r;++i) {
        for(j=0;j<c;++j) cin >> arr[i][j];
    }
    int ans = 0;
    int t; cin >> t;
    for(int i=0,j;i<r-2;++i) {
        for(j=0;j<c-2;++j) if(mask(i, j)>=t) ++ans;
    }
    cout << ans;

    return 0;
}