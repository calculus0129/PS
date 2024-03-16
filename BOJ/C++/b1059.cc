#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL)->sync_with_stdio(0);
    int l;
    cin >> l;
    set<int> s;
    for(int i=0, tmp;i<l;++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    int n;
    cin >> n;
    if(s.count(n)>0) cout << 0;
    else {
        auto it = upper_bound(s.begin(), s.end(), n);
        int b = *it - n, a = (s.begin() == it)?n:n - *--it;
        cout << b*a-1;
    }

    return 0;
}