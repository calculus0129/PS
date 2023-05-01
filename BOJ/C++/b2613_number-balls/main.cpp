#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
using namespace std;
int n, m, v[301];

bool check(int a)
{
    int arr[301]={v[0],};
    assert(arr[1]==0);
    int i=1, len=0;
    while(i<n)
    {
        if(arr[len]+v[i]<=a) {
            arr[len]+=v[i++];
        }
        else
        {
            arr[++len]=v[i++];
        }
    }
    return len+1<=m;
}

int bsearch(int s, int e)
{
    int mid;
    while(s+1<e)
    {
        mid = (s+e>>1);
        if(check(mid))
        {
            e=mid;
        }
        else
        {
            s=mid;
        }
    }
    return e;
}

int main()
{
    int ans, arr[301]={}, len, sums[301]={};
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        cin >> v[i];
    }
    for(int i=0;i<m;++i) arr[i] = v[i];
    for(int i=m;i<n;++i) arr[m-1] += v[i];
    ans = bsearch(*max_element(v, v+n)-1, *max_element(arr, arr+m));
    cout << ans << "\n";
    /// output should not be so greedy!
    /// because, we need all arr[i] to be nonzero!
    for(int i=1;i<m;++i)
    {
        arr[i]=1;
    }
    arr[0]=n-m+1;
    for(int i=0, prev_pos=0, j=0;i<m-1;++i) {
        for(j=0;j<arr[i];++j)
        {
            sums[i] += v[prev_pos+j];
        }
        prev_pos+=arr[i];
        while(sums[i]>ans)
        {
            sums[i]-=v[--prev_pos];
            //sums[i+1]+=v[prev_pos];
            arr[i]--;
            arr[i+1]++;
        }
    }
    for(int i=0;i<m;++i) cout << arr[i] << " ";

    return 0;
}

/*
5 3
1`1 1 1 1
=> 2 2 1

5 5
1 1 1 1 1
=> 1
1 1 1 1 1

8 3
5 4 2 6 9 3 8 7
=> 17
4 2 2

5 4
1 1 1 1 1
=> 2
2 1 1 1

5 4
5 4 3 2 1
=> 5
1 1 2 1

*/
