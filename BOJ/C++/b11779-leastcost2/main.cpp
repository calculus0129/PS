#include <bits/stdc++.h>
typedef long long int LLI;
using namespace std;
typedef pair<int, LLI> P;
vector<P> graph[1001];
vector<int> ans;
int n;

typedef vector<int> path;
typedef pair<path, P> info;

pair<path, LLI> process_dijkstra(int start, int x)
{
    const LLI big = 10000000001LL;
    auto foo = [](const info a, const info b) {
        return (a.second.second==b.second.second)?(a.second.first>b.second.first):(a.second.second>b.second.second);
    };
    priority_queue<info, vector<info>, bool(*)(const info, const info)> pq(foo);
    pq.push(make_pair(vector<int>(1, start), make_pair(start, 0LL)));
    bool ischecked[1001]={};
    LLI d[1001];
    for(int i=1;i<=n;++i)
    {
        d[i]=big;
    }

    vector<path> paths(n+1);
    assert(paths[n-1].empty());

    int now;
    long long int cost;
    path cur_path;
    info f;
    while(!pq.empty())
    {
        f = pq.top(); pq.pop();
        cur_path = f.first;
        now = f.second.first;
        cost = f.second.second;
        if (ischecked[now])
        {
            continue;
        }
        ischecked[now] = true;
        d[now] = cost;
        paths[now] = cur_path;
        for(auto i : graph[now])
        {
            if(d[i.first] > cost+i.second)
            {
                d[i.first] = cost+i.second;
                paths[i.first] = paths[now];
                paths[i.first].push_back(i.first);
                pq.push(make_pair(paths[i.first], make_pair(i.first, d[i.first])));
            }
        }
    }
    return make_pair(paths[x], d[x]);
}

int main()
{
    int m;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> m;
    int a, b;
    long long int cost;
    while(m--)
    {
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
    }
    int st, en;
    cin >> st >> en;
    auto x = process_dijkstra(st, en);
    cout << x.second << endl;
    cout << x.first.size() << endl;
    for(auto e:x.first)
    {
        cout << e << " ";
    }

    return 0;
}
