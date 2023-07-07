#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int p, a, b, c, arr[4]={};
    cin >> p;
    while(p--) {
        cin >> a >> b >> c;
        if(a==1) arr[3]++;
        else if (b<3) arr[0]++;
        else if (b == 3) arr[1]++;
        else arr[2]++;
    }
    for(int i=0;i<4;++i) cout << arr[i] << '\n';
    
    return 0;
}