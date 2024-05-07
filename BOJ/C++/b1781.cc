#include <bits/stdc++.h>
using namespace std;

struct problem
{
    int ddl;
    int ramen;
    bool operator<(const problem &other) const
    {
        return ddl == other.ddl ? ramen < other.ramen : ddl > other.ddl;
    }
};

int main()
{
    priority_queue<problem> pq;
    priority_queue<int, vector<int>, greater<int>> ramenq;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0, a, b; i < n; ++i)
    {
        cin >> a >> b;
        pq.push({a, b});
    }
    int t = 1, ramen = 0;
    problem tmp;
    while (!pq.empty())
    {
        tmp = pq.top();
        pq.pop();
        if (tmp.ddl < t)
        {
            if (ramenq.top() < tmp.ramen)
            {
                ramen += tmp.ramen - ramenq.top();
                ramenq.pop();
                ramenq.push(tmp.ramen);
            }
            else
                continue;
        }
        else
        {
            ramenq.push(tmp.ramen);
            ramen += tmp.ramen;
            ++t;
        }
    }
    cout << ramen;
    return 0;
}