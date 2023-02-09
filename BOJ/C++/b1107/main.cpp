#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int target, visited[MAX+1], seen[MAX+1];
vector<int> active;
int bfs()
{
    queue<int> q, nxt_q;
    const int N = active.size();
    int nxt, i, f, l = abs(target-100), cnt=0;
    if(!l) return 0;

    for(int i : active)
    {
        nxt_q.push(i);
    }

    while(!visited[target] && !nxt_q.empty())
    {
        ++cnt;
        swap(q, nxt_q);
        while(!q.empty())
        {
            f=q.front();
            q.pop();
            l = min(l, cnt+abs(target - f));
            visited[f]=1;
            for(i=0;i<N;++i)
            {
                nxt = 10*f+active[i];
                if(nxt>=0&&nxt<=MAX&&!seen[nxt])
                {
                    seen[nxt]=1;
                    nxt_q.push(nxt);
                }
            }
        }
    }
    return (visited[target]?min(cnt, l):l);
}
int main()
{
    int m,a, inactive[10]={};
    cin.tie(0)->sync_with_stdio(0);
    cin >> target >> m;
    while (m--)
    {
        cin >> a;
        inactive[a]=1;
    }
    for(int i=0;i<10;++i) if (!inactive[i]) active.push_back(i);
    cout << bfs();
    return 0;
}
