#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int dp[3][101010]={};
    for(int a, b, c, i=0;i<n;++i)
    {
        cin >> a >> b >> c;
        dp[0][i]=a+b;
        dp[1][i]=b+c;
        dp[2][i]=c+a;
    }
    sort(dp[0], dp[0]+n, greater<int>());
    sort(dp[1], dp[1]+n, greater<int>());
    sort(dp[2], dp[2]+n, greater<int>());
    int ans=0;
    for(int z=0, sum, i;z<3;++z)
    {
        sum=0;
        for(i=0;i<k;++i) sum+=dp[z][i];
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}
