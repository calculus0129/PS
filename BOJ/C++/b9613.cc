#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 재현이
// 1. 1번부터 n번까지의 번호가 적힌 카드가 있다.
// 2. 1번부터 n번까지의 번호가 적힌 카드를 임의의 순서로 섞는다.
// 3. 1번부터 n번까지의 번호가 적힌 카드를 순서대로 나열한다.
// 4. 1번부터 n번까지의 번호가 적힌 카드를 다시 임의의 순서로 섞는다.
// 5. 1번부터 n번까지의 번호가 적힌 카드를 순서대로 나열한다.
// 6. 1번부터 n번까지의 번호가 적힌 카드를 다시 임의의 순서로 섞는다.
// 7. 1번부터 n번까지의 번호가 적힌 카드를 순서대로 나열한다.
// 8. 1번부터 n번까지의 번호가 적힌 카드를 다시 임의의 순서로 섞는다.

// 위와 같은 과정을 거친 후 1번부터 n번까지의 번호가 적힌 카드를 순서대로 나열했을 때, i번 카드의 번호가 i인 카드의 개수를 구하자.

ll mygcd(ll a, ll b) {
    if(a<b) swap(a, b);
    ll c;
    while(b>0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    vector<ll> a;
    while(T--) {
        int n; cin >> n;
        a.assign(n, 0LL);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans=0LL;
        for(int i=0,j;i<n-1;++i) {
            for(j=i+1;j<n;++j) {
                // cout << a[i] << " and " << a[j] << ": ";
                ans += mygcd(a[i], a[j]);
                // cout << mygcd(a[i], a[j]) << '\n';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}