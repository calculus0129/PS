#include <bits/stdc++.h>
using namespace std;
priority_queue<int> masses;
priority_queue<int> cokes;
size_t ans;

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // cout << (1000000000 >> 31); // 0
    // cout << (1000000000 >> 32); // warning: shift count >= width of type [-Wshift-count-overflow] 1806513472
    int n, k, l;
    cin >> n >> k >> l;

    for(int i=0, a;i<n;++i) {
        cin >> a;
        masses.push(a);
    }
    vector<int> coke_vec;
    coke_vec.resize(k);
    for(int i=0;i<k;++i) {
        cin >> coke_vec[i];
    }
    sort(coke_vec.begin(), coke_vec.end());

    for(int i=1;i<=n;++i) {
        cokes.push(upper_bound(coke_vec.begin(), coke_vec.end(), i) - lower_bound(coke_vec.begin(), coke_vec.end(), max(1, i-l+1)));
    }


    while(!masses.empty()) {
        ans += (masses.top() >> min(31, cokes.top()));
        masses.pop(); cokes.pop();
    }
    cout << ans;


    return 0;
}