#include <bits/stdc++.h>
using namespace std;
int coef[101][101] = {
    {0},
    {0},
    {1, -1,},
    {1,-2,1,},
    {1,-1,-1,1},
};
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    for(int i=5;i<=100;++i) {
        memcpy(coef[i], coef[i+1>>1], sizeof(int)*(i+1>>1));
        memcpy(coef[i]+(i>>1), coef[i+1>>1], sizeof(int)*(i+1>>1));
        if(i&1) {
            coef[i][i>>1]<<=1;
        }
    }
    int n, T; cin >> T;
    for(int cs=1;cs<=T;++cs) {
        cin >> n;
        vector<ll> arr(n);
        for(int i=0;i<n;++i) cin >> arr[i];
        ll s = 0LL;
        for(int i=0;i<n;++i) s += arr[i] * coef[n][i];
        cout << "Case #" << cs << ": " << (s>0?"Alice\n":"Bob\n") ;
    }
    return 0;
}