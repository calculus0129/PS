#include <bits/stdc++.h>
using namespace std;
typedef size_t ULL;
map<char, ULL> mp;
bool notzero[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, i, j;
    size_t l, ans=0;
    cin >> n;
    string s;
    i=n;
    while(i--) {
        cin >> s;
        notzero[s[0]-'A']=1;
        for(l=1ULL,j=s.size()-1;j>=0;--j) {
            mp[s[j]]+=l;
            l *= 10ULL;
        }
    }
    char zero;
    for(i=0;i<10;++i) if(!notzero[i]) {
        zero='A'+i;
        break;
    }
    for(++i;i<10;++i) if(!notzero[i] && mp['A'+i]<mp[zero]) zero = 'A'+i;
    priority_queue<ULL> pq;
    for(const auto &[key, val]:mp) if(key!=zero) {
        pq.push(val);
    }
    i=9;
    while(i>0 && !pq.empty()) {
        ans += pq.top() * i;
        pq.pop();
        i--;
    }
    cout << ans;

    return 0;
}