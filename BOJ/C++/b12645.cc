#include <bits/stdc++.h>
using namespace std;
int nxt(int n) {
    string s = to_string(n);
    int arr[10] = {0,}, warr[10]={0,};
    for(char c: s) if(c!='0') {
        arr[c-'0']++;
    }
    bool r = true;
    while(r) {
        r = false;
        s = to_string(++n);
        memset(warr, 0, sizeof(warr));
        for(char c: s) if(c!='0') {
            warr[c-'0']++;
        }
        for(int i=1;i<=9;++i) if(arr[i] != warr[i]) {
            r = true;
            break;
        }
    }
    return n;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for(int t=1;t<=T;++t) {
        int n; cin >> n;
        cout << "Case #" << t << ": " << nxt(n) << '\n';
    }
    return 0;
}