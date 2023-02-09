#include <bits/stdc++.h>
using namespace std;
int m[100], c[100], n, M;

bool check(int cost)
{
    vector<int> arr(cost+1, 0), brr(cost+1, 0);
    for(int i=0,j;i<n;++i)
    {
        arr=brr;//swap(arr, brr);
        for(j=c[i];j<=cost;++j)
        {
            brr[j] = max(brr[j], arr[j-c[i]]+m[i]);
        }
    }
    return brr[cost]>=M;
}

//https://www.acmicpc.net/blog/view/109
int cost(int hi)
{
    if(check(0))
    {
        return 0;
    }
    int lo=0, mid;
    while(lo+1<hi)
    {
        mid = (lo+hi>>1);
        if(check(mid) == false)
        {
            lo=mid;
        }
        else
        {
            hi=mid;
        }
    }
    return hi;
}

int main()
{
    int sum=0;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> M;
    for(int i=0;i<n;++i)
    {
        cin >> m[i];
    }
    for(int i=0;i<n;++i)
    {
        cin >> c[i];
        sum+=c[i];
    }


    cout << cost(sum);
    return 0;
}
