#include <bits/stdc++.h>
using namespace std;
string a, b;
int arr[4010][4010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    for(int i=1, ie=a.size(), j, je=b.size();i<ie;++i) {
        for(j=1;j<je;++j) if(a[i]==b[j]) {
            arr[i][j] = arr[i-1][j-1]+1;
        }
    }
    int ans=0;
    for(int i=1,ie=a.size(),j,je=b.size(), a;i<ie;++i) {
        a = *max_element(arr[i], arr[i]+je);
        if(a>ans) ans = a;
    }
    cout << ans;
    return 0;
}