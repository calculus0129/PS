#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
using namespace std;

vector<int> divisors;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, cnt=0, n, t; cin >> n >> t;
    for(int i=1;i<=t;++i) if(t % i == 0) divisors.push_back(i);
    while(n--) {
        cin >> a;
        if(t%a) {
            int idx = lower_bound(ALL(divisors), a)-divisors.begin();
            cnt += min((idx == divisors.size()?10001:divisors[idx])-a, a-divisors[idx-1]);
        }
    }
    cout << cnt;

    return 0;
}