#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, n; cin >> T;
    char w[1001];
    long long ans;
    for(int t=1;t<=T;++t) {
        ans = 1LL;
        cin >> w;
        n=strlen(w);
        memset(arr, 0, sizeof(arr));
        char p = w[0];
        arr[0] = arr[1] = 1;
        for(int i=1;i<n;++i) {
            arr[i+1]++;
            if(p != w[i]) {
                ++arr[i];
                if(i==1 || w[i-2] != w[i]) ++arr[i-1];
            }
            p = w[i];
        }
        for(int i=0;i<n;++i) {
            ans = ans * arr[i] % 1000000007;
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}