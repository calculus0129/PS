#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n=10, card[21], a, b, tmp[21];
    for(int i=1;i<=20;++i) card[i]=i;
    while(n--) {
        cin >> a >> b;
        for(int i=b;i>=a;--i) {
            tmp[b-i]=card[i];
        }
        for(int i=0;i<=b-a;++i) {
            card[a+i] = tmp[i];
        }
    }
    for(int i=1;i<=20;++i) cout << card[i] << ' ';
    return 0;
}