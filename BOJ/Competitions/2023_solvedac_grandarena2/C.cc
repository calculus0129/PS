// https://solved.ac/arena/2/editorial - 풀이 과정 봄.

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    int mx=0;
    for(int i=0;i<n;++i) {
        int v;
        cin >> v;
        mx = max(mx, v);
        pq.push(v);
    }
    int curmx = mx, ans = curmx - pq.top();
    while(pq.top() < mx) {
        int v = pq.top(); pq.pop();
        ans = min(ans, curmx - v);
        curmx = max(curmx, v<<1);
        pq.push(v<<1);
    }
    cout << min(curmx - pq.top(), ans) << endl;
    return 0;
}