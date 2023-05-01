#include <bits/stdc++.h>
using namespace std;

static int d[1001], D[1001];
static int toposort[1001];
static int v3[1001];
vector<int> graph[1001];
static int l;

void dfs(int node)
{
    //v1
    // static int l?
    for(int nxt : graph[node])
    {
        //v2?
        if(v3[nxt]) continue;
        dfs(nxt);
    }
    v3[node]=1;
    toposort[l++]=node;
}

int main()
{
    int n, k, i, a, b;
    cin.tie(0)->sync_with_stdio(0);
    int t, w;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        l=0;
        memset(toposort, 0, (n+1) * sizeof(int));
        memset(v3, 0, (n+1)*sizeof(int));
        memset(d, 0, (n+1)*sizeof(int));
        for(i=1;i<=n;++i)
        {
            graph[i].clear();
            cin >> D[i];
        }
        while(k--)
        {
            cin >> a >> b;
            graph[b].push_back(a);
        }
        cin >> w;
        dfs(w);
        for(i=0;i<l;++i)
        {
            for(auto x: graph[toposort[i]]) if (d[x]>d[toposort[i]])
            {
                d[toposort[i]]=d[x];
            }
            d[toposort[i]]+=D[toposort[i]];
        }
        cout << d[w] << endl;
    }

    return 0;
}
