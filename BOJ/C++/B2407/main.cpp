#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;
map<pair<int,int>,mpz_class> mp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, r;
    cin >> n >> r;
    if (r<(n>>1)) r=n-r;
    for(int i=0;i<=n-r;++i) mp[{i,0}]=mpz_class(1);
    for(int i=0;i<=r;++i) mp[{i,i}]=mpz_class(1);
    for(int i=2,j;i<r;++i) for(j=1;j<i;++j) mp[{i,j}] = mp[{i-1, j-1}] + mp[{i-1,j}];
    mp[{r-1,r}]=mpz_class(0);
    for(int i=0,j;i<=n-r;++i) for(j=i+1;j<=r;++j) mp[{i+r,j}] = mp[{i+r-1, j-1}] + mp[{i+r-1,j}];
    cout << mp[{n,r}];
    return 0;
}
