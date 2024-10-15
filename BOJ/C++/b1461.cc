#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int m, n; cin >> m >> n;
    vector<int> arrP, arrN, P, N;
    while(m--) {
        int a; cin >> a;
        if(a>0) arrP.push_back(a);
        else if(a<0) arrN.push_back(-a);
    }
    sort(ALL(arrP)); sort(ALL(arrN));
    for(int i=arrP.size()-1;i>=0;i-=n) {
        P.push_back(arrP[i]);
    }
    
    for(int i=arrN.size()-1;i>=0;i-=n) {
        N.push_back(arrN[i]);
    }
    
    int ans = 0;
    
    // // Debug
    // cout << "P:\n";
    // for(int p: P) cout << p << ' ';
    // cout << "\nN:\n";
    // for(int p: N) cout << p << ' ';
    // cout << "\n";

    for(int p: P) ans += p;
    for(int p: N) ans += p;
    ans<<=1;
    ans -= max(P.empty()?0:P.front(), N.empty()?0:N.front());
    cout << ans;

    return 0;
}