#include <bits/stdc++.h>
using namespace std;
int D[101010];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<int,int> mp{{0,0}}, mp_i{make_pair(0,0)};
    int n, i, a, b, siz=0;
    cin >> n;
    int vv[101010]={0,};
    vector<int> k(n+1), v(n+1);
    for(i=1;i<=n;++i) {
        cin >> a >> b;
        k[i]=a;
        mp.insert({a, b});
        mp_i.insert(make_pair(b, a));
    }
    sort(k.begin(), k.end());
    set<int> s(k.begin()+1, k.end());
    for(i=1;i<=n;++i) {
        v[i]=mp[k[i]];
    }
    vv[0]=(1<<31); // -...
    for(i=1;i<=n;++i) {
        vv[D[i] = lower_bound(vv, vv+siz+1, v[i])-vv] = v[i];
        if(D[i]>siz) ++siz;
    }
    int x=~(1<<31), d=siz;
    for(i=n;i&&d;--i) if(D[i]==d && v[i]<x) {
        s.erase(s.find(mp_i[x=v[i]])); --d; ;
    }
    cout << n-siz << endl;
    for(auto j=s.begin(), e=s.end();j!=e;++j) cout << *j << '\n';

    return 0;
}