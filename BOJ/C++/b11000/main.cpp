#include <bits/stdc++.h>
using namespace std;
struct course {
    int s,t;
    bool operator<(const course &other) {
        return (s==other.s?t<other.t:s<other.s);
    }
};
int main()
{
    int n, s, t, cnt = 0;
    priority_queue<int,vector<int>,greater<int>> pq2;
    /// pq2.push(1); pq2.push(2); assert(pq2.top()==1);

    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<course> c(n, {0,0});

    for(int i=0;i<n;++i)
    {
        cin >> s >> t;
        c[i].s = s;
        c[i].t = t;
    }
    sort(c.begin(), c.end());

    pq2.push(c[0].t);

    for(int i=1;i<n;++i) {
        t = pq2.top();
        if(t<=c[i].s) {
            pq2.pop();
            pq2.push(c[i].t);
        }
        else {
            pq2.push(c[i].t);
        }
    }

    cout << pq2.size();

    return 0;
}
