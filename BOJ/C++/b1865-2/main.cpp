#include <bits/stdc++.h>
#define MAX 5000001
using namespace std;
struct edge
{
    int s, e, t;
};

int main()
{
    int ts, dist[501][501]={{}}, n, m, w, s, e, t, r;
    int i, j;
    cin.tie(0)->sync_with_stdio(0);
    cin >> ts;
    vector<edge> edges;

    while(ts--)
    {
        r=0;
        cin >> n >> m >> w;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                dist[i][j] = (i==j?0:MAX);
            }
        }
        for(i=0;i<m;++i)
        {
            cin>>s>>e>> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }
        for(i=0;i<w;++i)
        {
            cin>>s>>e>>t;
            edges.push_back({s, e, -t});
        }

        // Bellman-Ford
        for(i=0;i<n && !r;++i)
        {
            for(edge e : edges)
            {
                for(j=1;j<=n && !r;++j)
                {
                    if(dist[j][e.e]>dist[j][e.s]+e.t) {
                        dist[j][e.e]=dist[j][e.s]+e.t;
                        if(dist[j][j]<0)
                        {
                            r=1;
                            break;
                        }
                    }
                }
            }
        }
        /*
        for(int i=1;i<=n&&!r;++i)
        {
            if(dist[i][i]<0)
            {
                r=1
            }
        }
        */
        cout << (r?"YES\n":"NO\n");

        edges.clear();
    }



    return 0;
}
