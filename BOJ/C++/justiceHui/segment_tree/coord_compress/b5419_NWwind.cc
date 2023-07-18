#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, n, a, b, i;
    cin >> t;
    typedef pair<int,int> pii;
    vector<pii> v;
    while(t--) {
        v.erase(v.begin(), v.end());
        cin >> n;
        i=n;
        while(i--) {
            cin >> a >> b;
            v.push_back({a, b});
        }
        v.sort(v.begin(), v.end(), )
    }
    return 0;
}