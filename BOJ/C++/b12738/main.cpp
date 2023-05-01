#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, arr[1000001]={}, dp[1000001]={};
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i) cin >> arr[i];
    int l=1;
    dp[0]=arr[0];
    for(int i=1;i<n;++i)
    {
        if(dp[l-1]<arr[i])
        {
            dp[l++]=arr[i];
        }
        else
        {
            *(lower_bound(dp, dp+l, arr[i]))=arr[i];
        }
    }
    cout << l;

    return 0;
}
