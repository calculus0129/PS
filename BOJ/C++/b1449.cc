#include <bits/stdc++.h>
using namespace std;
int n, l;
bool leak[2001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> l;
    l--;
    while(n--) {
        int a; cin >> a;
        leak[a] = true;
    }
    int ans = 0;
    for(int i=1,j;i<=1000;++i) if(leak[i]) {
        ++ans;
        for(j=0;j<l;++j) leak[i++] = false;
    }
    cout << ans;
    return 0;
}