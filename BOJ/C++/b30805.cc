#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
int m, n;
char arr[101], brr[101];
typedef pair<int,int> pii;
pii dp[101][101];
map<pii, string> dict;

int compare(const pii &a, const pii &b) {
    if(DEBUG) {
        cout << "comparing\n(" << a.first << ", " << a.second << "): " << dict[a] << " and\n("
        << b.first << ", " << b.second << "): " << dict[b] << " ...\n";
    }
    return dict[a].compare(dict[b]);
}

string max_string(string s, char c) {
    for(int i=0,e=s.size();i<e;++i) if(s[i]<c) {
        s[i]=c;
        s.resize(i+1);
        return s;
    }
    return s+c;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> m;
    for(int i=1, a;i<=m;++i) {
        cin >> a;
        arr[i]=a;
    }
    cin >> n;
    for(int i=1, b;i<=n;++i) {
        cin >> b;
        brr[i] = b;
    }
    for(int i=1;i<=m;++i) dict[{i,0}]="";
    for(int j=1;j<=n;++j) dict[{0,j}]="";
    dict[{0,0}]="";
    pii tmp;
    for(int i=1,j;i<=m;++i) {
        for(j=1;j<=n;++j) {
            tmp = compare(dp[i-1][j], dp[i][j-1])>0?dp[i-1][j]:dp[i][j-1];
            if(arr[i]==brr[j]) {
                string s = max_string(dict[dp[i-1][j-1]], arr[i]);
                if(s.compare(dict[tmp])>0) {
                    if(DEBUG) {
                        cout << "new string generated: dp[" << i << ',' << j << "]=" << s << '\n';
                    }
                    dict[tmp={i,j}]=s;
                }
            }
            dp[i][j] = tmp;
        }
    }
    string ans = dict[dp[m][n]];
    cout << ans.size() << '\n';
    for(char c: ans) cout << (int)c << ' ';
    return 0;
}