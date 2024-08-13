#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
char str[200001];
int n;
int ans;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> str;
    map<pii, int> mp;
    mp[{0,0}]=-1; // J-O, O-I
    pii cur = {0,0};
    for(int i=0;i<n;++i) {
        switch(str[i]) {
            case 'J':
                cur.first++;
                break;
            case 'O':
                cur.first--;
                cur.second++;
                break;
            default:
                cur.second--;
        }
        if(mp.find(cur) == mp.end()) {
            mp[cur] = i;
        } else {
            ans = max(ans, i-mp[cur]);
        }
    }
    cout << ans;
    return 0;
}