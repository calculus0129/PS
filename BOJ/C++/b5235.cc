#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    int n, sum;
    // vector<int> arr;
    while(T--) {
        cin >> n;
        sum = 0;
        for(int i=0, a;i<n;++i) {
            cin >> a;
            if(a&1) a = -a;
            sum += a;
        }
        cout << (sum>0 ? "EVEN" : sum == 0 ? "TIE" : "ODD") << '\n';
    }
    return 0;
}