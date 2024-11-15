#include <bits/stdc++.h>
using namespace std;
char s[101010];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    cin >> s;
    int a=0, b=0;
    for(int i=0;i<n;++i) {
        if(s[i]=='2') ++a;
        else ++b;
    }
    if(a == b) cout << "yee";
    else if(a>b) cout << 2;
    else cout << 'e';
    
    return 0;
}