#include <bits/stdc++.h>
using namespace std;
int m, n;
unordered_map<int, int> mp, inv_mp;
unordered_map<int, unordered_set<int>> match;
bool visited[301];

bool bipMatching(int a) {
    for(int i: match[a]) if(inv_mp.find(i) == inv_mp.end()) {
        mp[a] = i;
        inv_mp[i] = a;
        return true;
    }
    for(int b: match[a]) if(!visited[b]) {
        visited[b] = true;
        if(bipMatching(inv_mp[b])) {
            mp[a] = b;
            inv_mp[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int k1, k2, troll1=0, troll2=0;
    cin >> m >> n >> k1 >> k2;

    for(int i=0, a, b;i<k1;++i) {
        cin >> a >> b;
        match[a].insert(b);
    }
    for(int i=1;i<=m;++i) {
        memset(visited, 0, sizeof(visited));
        if(bipMatching(i)) troll1++;
    }
    mp.clear();
    inv_mp.clear();
    match.clear();

    for(int i=0, a, b;i<k2;++i) {
        cin >> a >> b;
        match[a].insert(b);
    }
    for(int i=1;i<=m;++i) {
        memset(visited, 0, sizeof(visited));
        if(bipMatching(i)) troll2++;
    }

    // cout << troll1 << ' ' << troll2 << '\n';

    cout << (troll1<troll2?"네 다음 힐딱이":"그만 알아보자");
    
    return 0;
}