#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> stk, inp(n);
    stk.reserve(n);
    for(int i=0;i<n;++i) {
        cin >> inp[i];
    }
    for(int i=0;i<n;++i) {
        auto i1 = lower_bound(stk.begin(), stk.end(), inp[i], [](int a, int b) -> bool { return a>b; }),
            i2 = upper_bound(stk.begin(), stk.end(), inp[i], [](int a, int b) -> bool { return a>b; });
        ans += stk.end() - i1;
        if(!stk.empty() && i1!=stk.begin()) ans++;
        stk.erase(i2, stk.end());
        stk.push_back(inp[i]);
    }
    cout << ans;
    return 0;
}