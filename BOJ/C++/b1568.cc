#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n,cnt=0,c=1;
    cin >> n;
    while(n) {
        if(n<c) c=1;
        n-=c++;
        ++cnt;
    }
    cout << cnt;
    return 0;
}