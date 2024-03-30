#include <bits/stdc++.h>
using namespace std;
map<int, int> dict;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0, a;i<n;++i) {
        cin >> a;
        while((a&1) == 0) a>>=1;
        dict[a]++;
    }
    int cnt=0;
    for(auto i = dict.begin(), e = dict.end();i!=e;++i) {
        if(i->second > cnt) cnt = i->second;
    }
    cout << cnt;

    return 0;
}