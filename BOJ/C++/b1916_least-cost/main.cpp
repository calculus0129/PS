#include <bits/stdc++.h>
#define BIG 10000000001LL
using namespace std;
typedef pair<int,long long int> p;
vector<p> graph[1001];
long long int d[1001];
int n;

void process_dijkstra(int from)
{
    bool checked[1001];
    for(int i=1;i<=n;++i)
    {
        checked[i]=false;
        d[i] = BIG;
    }
    static auto cmp = [](p x, p y) {
        return (x.second==y.second)?x.first>y.first:x.second>y.second;
    };
    priority_queue<p, vector<p>, bool(*)(p, p)> pq(cmp);
    pq.push(make_pair(from, 0));
    p f;
    while(!pq.empty())
    {
        f = pq.top(); pq.pop();
        if(checked[f.first])
        {
            continue;
        }
        checked[f.first] = true;
        d[f.first] = f.second;
        for(auto i: graph[f.first])
        {
            if(d[i.first] > f.second + i.second)
            {
                d[i.first] = f.second + i.second;
                pq.push(make_pair(i.first, f.second + i.second));
            }
        }
    }
}

int main()
{
    int a, b, m;
    long long int w;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    cin>>m;
    while(m--)
    {
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(b, w));
    }
    int s, e;
    cin>>s>>e;
    process_dijkstra(s);

    cout << d[e];

    return 0;
}
