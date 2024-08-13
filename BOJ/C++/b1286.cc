#include <bits/stdc++.h>
using namespace std;
int m, n;
char arr[100][101];
typedef long long ll;
map<char, ll> mp;

void work() {
    for(int i=0,j;i<2*m;++i) for(j=0;j<2*n;++j) mp[arr[i][j]] += (i+1)*(2*m-i)*(j+1)*(2*n-j);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for(int i=0;i<m;++i) cin >> arr[i];
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) arr[i][j+n] = arr[i][j];
    memcpy(&arr[m][0], &arr[0][0], sizeof(char)*m*101);
    // Correctly doubling rows
    // for(int i=0;i<m;++i) {
    //     memcpy(&arr[i+m][0], &arr[i][0], sizeof(char)*(2*n));
    // }
    // for(int i=0;i<2*m;++i) cout << arr[i] << '\n';
    work();
    for(char a='A';a<='Z';++a) {
        cout << mp[a] << '\n';
    }
    return 0;
}