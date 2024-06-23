#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        cout << a[2]-a[0] << '\n';
    }
    return 0;
}