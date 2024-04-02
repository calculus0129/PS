#include <bits/stdc++.h>
using namespace std;
int n;
char s[7];
void DEXOR(int x, int y) {
    if(x == 0 && y == 0) {
        s[0]='0';
        return;
    }
    n = max(int(log10(x)), int(log10(y)))+1;
    for(int i=0;i<n;++i) {
        s[n-1-i] += '0'+((x%10<=2 && y%10<=2) || (x%10>=7 && y%10>=7)?0:9);
        x/=10;
        y/=10;
    }
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    DEXOR(x, y);
    cout << s;

}