#include <bits/stdc++.h>
using namespace std;
struct P {
    int s, e;
    bool operator<(const P &rhs) const {
        return (s==rhs.s)?e<rhs.e:s<rhs.s;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, ans=1, e;
    cin >> n;
    vector<P> vec;
    P tmp;
    for(int i=1;i<=n;++i) {
        cin >> tmp.s >> tmp.e;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(vec[0].e);
    for(int i=1;i<n;++i) {
        e = pq.top();
        if(e<=vec[i].s) {
            pq.pop();
            pq.push(vec[i].e);
        } else {
            pq.push(vec[i].e);
            ++ans;
        }
    }
    cout << ans;

    return 0;
}