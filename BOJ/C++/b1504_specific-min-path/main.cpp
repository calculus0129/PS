#include <bits/stdc++.h>
#define BIG 200000001
using namespace std;
int n, arr[801][801];
vector<pair<int,int>> graph[801];

void process_dijkstra(int from)
{
    bool checked[801];
    for(int i=1;i<801;++i) checked[i]=false;
    //https://www.acmicpc.net/blog/view/114
    static auto cmp = [](pair<int,int> x, pair<int,int> y) {
        return (x.second==y.second)?x.first>y.first:x.second>y.second;
        //return true;
    };
    // (vertex_no, total_cost)
    priority_queue<pair<int,int>, vector<pair<int,int>>, bool(*)(pair<int,int>, pair<int,int>)> pq(cmp);
    pq.push(make_pair(from, 0));
    pair<int,int> f;
    while(!pq.empty()) {
        f = pq.top(); pq.pop();
        if (checked[f.first])
        {
            continue;
        }
        checked[f.first] = true;
        arr[from][f.first] = f.second;
        for(auto i: graph[f.first]) {
            if(arr[from][i.first]>f.second+i.second) {
                arr[from][i.first]=f.second+i.second;
                pq.push(make_pair(i.first, f.second+i.second));
            }
        }
    }
}

int work(int v1, int v2) {
    return min(arr[1][v1]+arr[v1][v2]+arr[n][v2], arr[1][v2]+arr[v1][v2]+arr[n][v1]);
}

int main()
{
    int a, b, w, e;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> e;
    for(int i=n, j;i>0;--i) for(j=n;j>0;--j) arr[i][j]=BIG;
    /*vector<pair<int,int>> tmp;
    for(int i=n;i>=0;--i) graph.push_back(tmp);*/
    //assert(graph[8].empty());
    while(e--) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    int v1, v2;
    cin >> v1 >> v2;
    process_dijkstra(1);
    process_dijkstra(n);
    process_dijkstra(v1);
    int ans = work(v1, v2);
    if(ans >= BIG)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    return 0;
}
