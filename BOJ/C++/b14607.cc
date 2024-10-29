#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    cout << (n*(n-1)>>1);
    return 0;
}