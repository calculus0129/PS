#include <bits/stdc++.h>
#define MAX 100000//1000000
//#define all(v) v.begin(), v.end()
//#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
//#define IDX(v, x) lower_bound(all(v), x) - v.begin()
using namespace std;

int main()
{
    int n, m, r=1;
    int T[MAX+1]={};
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    vector<int> t(n, 0);
    for(int i=0;i<n;++i)
    {
        cin >> t[i];
        T[t[i]] = 3;
    }
    for(int i=n-1, v=t[n-1];i>=0;--i)
    {
        v=min(v, t[i]);
        while(v>=0 && T[v]==3) --v;
        if(v<0 || t[i]-v>m)
        {
            r=0;
            break;
        }
        T[v--]=2;
    }
    if(r==1)
    {
        for(int i=n-1, v=t[n-1];i>=0;--i)
        {
            v=min(v, t[i]);
            while(v>=0 && T[v]!=0) --v;
            if(v<0)
            {
                r=0;
                break;
            }
            T[v--]=1;
        }
        /*
        for(int i=0, cnt=0;i<=t[n-1];++i)
        {
            if (T[i]==0)
            {
                ++cnt;
            }
            else if (T[i]==2)
            {
                --cnt;
                if(cnt<0)
                {
                    r=0;
                    break;
                }
            }
        }*/
    }
    cout << (r==1?"success":"fail");


    return 0;
}

/**
1 2
1
=> fail

1 1
2
=> success

2 1
1 3
=> fail

2 1
2 4
=> fail

2 1
3 5
=> success

6 3
5 6 12 15 16 17
=> fail

6 4
5 6 12 15 16 17
=> success

6 4
5 6 11 15 16 17
=> success

6 3
5 6 12 14 16 17
=> success

6 3
4 6 12 15 16 17
=> fail

6 3
5 6 12 14 16 17
=> success

7 3
5 6 13 16 17 19 20
=> fail

7 3
5 6 13 15 17 19 20
=> success

7 4
5 6 13 16 17 19 20
=> success

7 3
5 6 12 15 16 18 19
=> fail

*/
