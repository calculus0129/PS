#include <bits/stdc++.h>
using namespace std;

int idx(int x) {
    return x - x/3 - x/5 + x/15;
}

int middle(int lo, int hi) {
    // int ret = lo+hi>>1;
    int ret = (lo&hi)+((lo^hi)>>1);
    if(ret%3 == 0 || ret%5 == 0) ++ret;
    if(ret%3 == 0 || ret%5 == 0) ++ret;
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int lo=0, hi=INT_MAX, mid, x, ans;
    mid = middle(lo, hi);
    cin >> x;
    while(mid!=hi && mid!=lo) {
        if(idx(mid)<x) lo = mid;
        else hi = mid;
        mid = middle(lo, hi);
        // cout << "lo: " << lo << ", hi: " << hi << '\n';
    }
    for(ans=lo+1;ans<=hi;++ans) if(ans%3 && ans%5) {
        if(idx(ans) == x) break;
    }
    cout << ans;

    return 0;
}