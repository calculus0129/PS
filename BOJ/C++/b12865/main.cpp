#include <bits/stdc++.h>
using namespace std;

struct mat
{
    int w, v;
    bool operator<(const mat & a)
    {
        return (w==a.w)?a.v<v:w<a.w;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k, arr[101][100001], i, j;
    mat mats[101]={};
    memset(arr, 0, sizeof(arr));
    cin >> n >> k;

    for(i=1;i<=n;++i)
    {
        cin >> mats[i].w >> mats[i].v;
    }

    sort(mats+1, mats+n+1);

    for(i=1;i<=n;++i)
    {
        for(j=1;j<mats[i].w;++j)
        {
            arr[i][j]=arr[i-1][j];
        }
        for(;j<=k;++j)
        {
            arr[i][j] = max(mats[i].v+arr[i-1][j-mats[i].w], arr[i-1][j]);
        }
    }

    cout << arr[n][k];

    return 0;
}
