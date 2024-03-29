#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    bool valid = true;
    int j=-1, cnt;
    for(int i=0,e=s.size(), k;i<e;++i) {
        if(s[i] == 'X') {
            if(j==-1) j = i;
        }
        else if(j>-1) {
            cnt = i-j;
            if(cnt & 1) {
                valid = false;
                break;
            }
            else if(cnt>>1&1) {
                for(k=j;k<i-2;++k) s[k] = 'A';
                s[i-2] = s[i-1] = 'B';
            }
            else {
                for(k=j;k<i;++k) s[k] = 'A';
            }
            j = -1;
        }
    }
    if(j>-1) {
        int i = s.size();
        cnt = i-j;
        if(cnt & 1) {
            valid = false;
        }
        else if(cnt>>1&1) {
            for(int k=j;k<i-2;++k) s[k] = 'A';
            s[i-2] = s[i-1] = 'B';
        }
        else {
            for(int k=j;k<i;++k) s[k] = 'A';
        }
        j = -1;
    }
    cout << (valid?s:"-1");
    return 0;
}