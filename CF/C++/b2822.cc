#include <bits/stdc++.h>
using namespace std;
struct score {
    int amount, num;
    bool operator<(const score &other) const {
        return amount < other.amount;
    }
};
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    priority_queue<score> pq;
    for(int i=1, a;i<=8;++i) {
        cin >> a;
        pq.push({a, i});
    }
    int s = 0;
    vector<int> arr;
    for(int i=0;i<5;++i) {
        s += pq.top().amount;
        arr.push_back(pq.top().num);
        pq.pop();
    }
    sort(arr.begin(), arr.end());

    cout << s << '\n';
    for(int i=0;i<5;++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}