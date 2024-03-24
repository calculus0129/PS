#include <bits/stdc++.h>
using namespace std;
int imos[500010];
vector<int> sum;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    sum.reserve(500002);
    int n, h;
    cin >> n >> h;
    n >>= 1;
    for(int i=0, a, b;i<n;++i) {
        cin >> a >> b;
        ++imos[1];
        --imos[a+1];
        ++imos[h-b+1];
        --imos[h+1];
    }
    sum.resize(h+1);
    for(int i=1;i<=h;++i) {
        sum[i] = sum[i-1]+imos[i];
    }
    sum.erase(sum.begin());
    sort(sum.begin(), sum.end());
    cout << sum[0] << ' ' << upper_bound(sum.begin(), sum.end(), sum[0]) - sum.begin();

    return 0;
}