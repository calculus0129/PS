#include <bits/stdc++.h>
using namespace std;
int nt, ns;
char t[1010], s[1010], ss[1010];

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> t;
    cin >> s;
    nt = strlen(t), ns = strlen(s);
    bool r = false;
    for(int i=0, j;!r && i< ns;++i) {
        strcpy(ss, s+i);
        for(j=0;j<i;++j) {
            ss[ns-i+j] = s[j];
        }
        // assert(ss[ns] == '\0');
        // cout << ss << '\n';
        if(strstr(t, ss)!=NULL) r = true;
    }
    cout << (r?"yes":"no");

    return 0;
}