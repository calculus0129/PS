#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, arr[3];
    cin >> n;
    for(int i=0, a;i<n;++i) {
        cin >> a;
        pq.push(a);
    }
    for(int i=0;i<3;++i) {arr[i] = pq.top(); pq.pop();}
    while(arr[0]>=arr[1]+arr[2] && !pq.empty()) {
        arr[0]=arr[1];
        arr[1]=arr[2];
        arr[2]=pq.top();
        pq.pop();
    }
    cout << (arr[0]>=arr[1]+arr[2] ? -1 : arr[0]+arr[1]+arr[2]);

    return 0;
}