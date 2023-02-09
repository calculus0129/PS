#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;

int bfs()
{
    int visited[101]={}, seen[101]={};
    int cnt=-1, f=1, nxt, i;
    queue<int> q, nxt_q;

    cnt++;
    visited[f]=seen[f]=1;
    for(i=1;i<=6;++i)
    {
        nxt=i+f;
        seen[nxt] = 1;
        nxt_q.push(mp[nxt]);
    }

    while(!visited[100])
    {
        ++cnt;
        swap(q, nxt_q);
        while(!q.empty())
        {
            f = q.front();
            q.pop();
            visited[f]=1;
            for(i=1;i<=6;++i)
            {
                nxt=i+f;
                if(nxt<=100 && !seen[nxt])
                {
                    seen[nxt]=1;
                    nxt_q.push(mp[nxt]);
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int a,b,n,m,i;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(i=0;i<n;++i)
    {
        cin >> a >> b;
        mp[a]=b;
    }
    for(i=0;i<m;++i)
    {
        cin>>a>>b;
        mp[a]=b;
    }
    for(i=1;i<=100;++i) if(mp.find(i)==mp.end())
    {
        mp[i]=i;
    }
    cout << bfs();

    return 0;
}
