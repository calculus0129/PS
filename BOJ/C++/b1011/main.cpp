// This is actually b1374
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct lecture
{
    int s, e;
};

vector<lecture> arr;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    cin.tie(0)->sync_with_stdio(0);
    size_t n, i; cin>>n; i=n;
    int a;
    lecture lec;
    while(i--)
    {
        cin >> a >> lec.s >> lec.e;
        arr.push_back(lec);
    }
    sort(arr.begin(), arr.end(), [](const lecture l1, const lecture l2) {
         return (l1.s==l2.s)?(l1.e<l2.e):(l1.s<l2.s);
    });
    size_t ans=1ULL;
    pq.push(arr[i++].e);
    for(;i<n;++i)
    {
        if(pq.top() <= arr[i].s)
        {
            pq.pop();
        }
        pq.push(arr[i].e);
        ans = max(ans, pq.size());
    }
    cout << ans;
    return 0;
}
