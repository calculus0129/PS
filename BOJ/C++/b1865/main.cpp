#include <bits/stdc++.h>
#define INF 2000000000//5000001
using namespace std;
vector<int> dist;
int n;
struct edge
{
    int s, e, t;
};
//int yum =
vector<edge> edges;

bool neg_circuit_exist()
{
    int i=-1;
    while(++i<n) // n번 반복
    {
        for(edge e : edges) if(dist[e.s]!=INF && dist[e.e] > dist[e.s] + e.t)
        {
            dist[e.e] = dist[e.s] + e.t;
        }
    }
    vector<int> tmp=dist;
    for(edge e : edges) if(dist[e.s]!=INF && dist[e.e] > dist[e.s] + e.t)
    {
        dist[e.e] = dist[e.s] + e.t;
    }
    return dist != tmp;
}

int main()
{
    dist.reserve(1001);
    edges.reserve(6000);
    int tc, m, w, s, e, t;
    cin.tie(0)->sync_with_stdio(0);
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m>>w;
        vector<int> tmp(n+1, INF);
        dist = tmp;
        dist[0]=0;
        for(int i=0;i<m;++i)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(int i=0;i<w;++i)
        {
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }
        // '가짜' 정점 => 음수 순환 cycle 존재 시 분명히 n+2번 0번 vertex로부터 edge를 갈 때 0번 dist는 음수여야 한다.
        for(int i=1;i<=n;++i)
        {
            edges.push_back({0,i,0});
            //edges.push_back({i,0,0});
        }
        cout << (neg_circuit_exist()?"YES\n":"NO\n");
        edges.clear();
        dist.clear();
    }

    return 0;
}
