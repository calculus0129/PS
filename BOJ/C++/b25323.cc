#include <bits/stdc++.h>
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)

using namespace std;
typedef long long ll;
vector<ll> arr, brr;

int n;

ll gcd(ll a, ll b) {
    if(b==0LL) return a;
    return gcd(b, a%b);
}

bool equivalent(ll a, ll b) {
    ll g = gcd(a, b);
    a/=g, b/=g;
    ll aa = sqrt(a), bb = sqrt(b);
    return aa*aa == a && bb*bb == b;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    arr.reserve(500001); brr.reserve(500001);
    cin >> n;
    ll a;
    for(int i=0;i<n;++i) {
        cin >> a;
        arr.push_back(a);
        brr.push_back(a);
    }
    sort(ALL(brr));
    bool r = true;
    for(int i=0;i<n && r;++i) r = equivalent(arr[i], brr[i]);
    cout << (r?"YES":"NO");

    return 0;
}