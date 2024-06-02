#include <bits/stdc++.h>
using namespace std;
char arr[52][52];
int trr[52];
int len;
int main() {
    string cmd;
    char c;
    int rt, t, current_time=0;

    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=1, j;i<=n;++i) {
        cin >> cmd;
        // cout << "cmd: " << cmd << '\n';
        if(cmd == "type") {
            cin >> c >> t;
            // cout << "c: " << c << ", t: " << t << '\n';
            current_time = trr[i] = t;
            strcpy(arr[i], arr[i-1]);
            arr[i][strlen(arr[i])]=c;
        } else {
            cin >> rt >> t;
            // cout << "rt: " << rt << ", t: " << t << '\n';
            trr[i] = t;
            current_time = max(0, t - 1 - rt);
            for(j=1;j<=i && trr[j]<=current_time;++j);
            strcpy(arr[i], arr[j-1]);
        }
    }
    // for(int i=1;i<=n;++i) {
    //     cout << trr[i] << ": " << arr[i] << '\n';
    // }
    cout << arr[n];

    return 0;
}