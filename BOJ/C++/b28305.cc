#include <bits/stdc++.h>
using namespace std;
int n, T, arr[200001];

bool check(int sem) {
    priority_queue<int, vector<int>, greater<int>> pq;
    while(sem--) pq.push(1);
    for(int i=0, t;i<n;++i) {
        t = pq.top(); pq.pop();
        if(t>arr[i]) return false;
        pq.push(max(t+T, arr[i]));
    }
    return true;
}

int work(int lo, int hi) {
    int mid;
    if(check(lo)) return lo;
    // else, check(lo) is false, check(hi) is true.
    while(lo+1<hi) {
        mid = lo+hi>>1;
        if(check(mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> T;
    for(int i=0;i<n;++i) cin >> arr[i];
    sort(arr, arr+n);
    cout << work(1, n);

    return 0;
}