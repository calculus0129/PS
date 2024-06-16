#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> w;

// largest matching index of cats
int l_index() {
    auto u = upper_bound(w.begin()+1, w.end(), k-w[0]);
    if(u == w.begin()+1) return -1;
    return (u-w.begin())-1;
}

int main() {
    vector<int> arr;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    w.reserve(5001);
    cin >> n >> k;
    w.resize(n);

    for(int i=0;i<n;++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());

    int ans = 0, li;
    while(w.size()>1) {
        li = l_index();
        if(li<0) break;
        w.erase(w.begin()+li);
        w.erase(w.begin());
        ++ans;
    }

    cout << ans;

    return 0;
}