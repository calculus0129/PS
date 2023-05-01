#include <bits/stdc++.h>
using namespace std;

int main()
{
    int need[101]={};
    cin.tie(0)->sync_with_stdio(0);
    int n, k, a, ls=1, le=0;
    cin >> n >> k;
    for(int i=1;i<=n;++i) need[i]=1;
    for(int i=0;i<k;++i)
    {
        cin >> a;
        need[a]=0;
    }
    int cost=0;
    for(int i=1, r=3;i<=n;++i)
    {
        if(need[i]==0)
        {
            ++r;
        }
        else
        {
            if(r>=3)
            {
                if(ls<=le) cost += 5 + 2*(le-ls+1);
                ls = i;
            }
            r=0;
            le = i;
        }
    }
    if(ls<=le) cost += 5 + 2*(le-ls+1);
    cout << cost;

    return 0;
}
