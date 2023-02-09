#include <bits/stdc++.h>
using namespace std;
int arr[128][128];
int nums[2];

void cut(const int r1, const int r2, const int c1, const int c2)
{
    int a = arr[r1][c1], r=1, mr=(r1+r2>>1), mc=(c1+c2>>1);
    for(int i=r1,j;i<r2&&r==1;++i) for(j=c1;j<c2;++j)
    {
        if(arr[i][j]!=a)
        {
            r=0;
            break;
        }
    }
    if(r)
    {
        ++nums[a];
    }
    else
    {
        cut(r1,mr,c1,mc);
        cut(r1,mr,mc,c2);
        cut(mr,r2,c1,mc);
        cut(mr,r2,mc,c2);
    }
}

int main()
{
    int n;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0,j;i<n;++i) for(j=0;j<n;++j) cin >> arr[i][j];
    cut(0,n,0,n);
    cout << nums[0] << endl << nums[1];
    return 0;
}
