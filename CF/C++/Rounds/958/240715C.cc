#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ones;

void work(ll m) {
    ones.clear();
    ll n = m;
    for(int i=0;n;++i,n>>=1) if(n&1) ones.push_back(i);
    // cout << '\n' << "The ones: ";
    // for(int i: ones) cout << i << ' ';
    // cout << "\n\n";
    int cnt = ones.size();
    if(cnt == 1) {
        cout << 1 << '\n' << m << '\n';
        return;
    }
    vector<vector<bool>> bits(cnt+1, vector<bool>(cnt, true));
    for(int i=0, j;i<cnt;++i) for(j=i;j<cnt;j+=2) bits[i][j] = false;

    // cout << "\nThe bits: \n";
    // for(int i=0, j;i<=cnt;++i) {
    //     for(j=0;j<cnt;++j) cout << bits[i][j];
    //     cout << '\n';
    // }
    // cout << '\n';

    cout << cnt+1 << '\n';
    for(const vector<bool> &vec: bits) {
        ll o=0LL;
        for(int i=0;i<cnt;++i) if(vec[i]) o|=1LL<<ones[cnt-i-1];
        cout << o << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    ones.reserve(55);
    cin >> t;
    while(t--) {
        ll m;
        cin >> m;
        // cout << (cnt==1?1:cnt+1) << '\n';
        work(m);
    }

    return 0;
}