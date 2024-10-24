#include <bits/stdc++.h>
using namespace std;

int sums[81];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, c; cin >> a >> b >> c;
    for(int i=1,j,k;i<=a;++i) {
        for(j=1;j<=b;++j) {
            for(k=1;k<=c;++k) {
                sums[i+j+k]++;
            }
        }
    }
    int cnt = 0;
    int ans = 0;
    for(int i=3;i<=80;++i) if(sums[i] > cnt) {
        cnt = sums[i];
        ans = i;
    }
    cout << ans;
    return 0;
}