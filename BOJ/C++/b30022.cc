#include <bits/stdc++.h>
using namespace std;
int n, a, b;

typedef long long int ll;

ll A[101010], B[101010];
ll sum;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for(int i=0;i<n;++i) {
        cin >> A[i] >> B[i];
        sum += B[i];
        pq.push((int)A[i]-(int)B[i]);
    }
    while(a--) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;

    return 0;
}