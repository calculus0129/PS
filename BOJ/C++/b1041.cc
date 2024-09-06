#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> diceMin(const vector<int> &arr) {
    int a = arr[0], b = arr[1], c = arr[2], d = arr[3], e = arr[4], f = arr[5];
    vector<int> ret, s = arr;
    ret.push_back(*min_element(s.begin(), s.end()));
    s = vector<int>({
        a + b, b + c, c + a,
        d + e, e + f, f + d,
        a + d, e + a,
        c + f, f + b,
        c + e, b + d
    });
    ret.push_back(*min_element(s.begin(), s.end()));
    s = vector<int>({
        a + b + c,
        a + b + d,
        a + d + e,
        a + c + e,
        f + b + c,
        f + c + e,
        f + e + d,
        f + b + d
    });
    ret.push_back(*min_element(s.begin(), s.end()));
    return ret;
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, a, b, c, d, e, f; cin >> n >> a >> b >> c >> d >> e >> f;
    if(n == 1) cout << a + b + c + d + e + f - max(max(max(a, b), max(c, d)), max(e, f));
    else {
        ll ans = 0LL;
        vector<int> dice({a, b, c, d, e, f});
        dice = diceMin(dice);
        ans += dice[0] * (5*(ll)(n-2)*(n-2) + 4*(n-2));
        ans += dice[1] * (4 + 8LL*(n-2));
        ans += dice[2] * 4;
        cout << ans;
    }
    return 0;
}