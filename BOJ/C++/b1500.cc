#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    lli s, k, res=1LL; cin >> s >> k;
    for(lli i=0LL, num=s/k;i<k-s%k;++i) res *= num;
    lli num=s/k+1;
    for(int i=0;i<s%k;++i) res *= num;
    cout << res;
    
    return 0;
}