#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    /*
    int arr[4]={},n,l,cnt,r=0,i,j,c=1;
    for(cin >> n;i<=n;j=++i,l=0,c=1)
    {
        while(j)
        {
            arr[l++]=j%10;
            j/=10;
        }
        r=arr[1]-arr[0];
        for(j=1;j<l-1;++j)
        {
            if(r!=arr[j+1]-arr[j])
            {
                c=0;
                break;
            }
        }
        cnt+=c;
    }
    cout << cnt;
    */
    int arr[4]={};
    int n,l,cnt=0,r,i,j,c=0; // 110 -> 99(O)
    //int n,l,cnt,r,i,j,c=0; // 110 -> 115(X)
    ///assert(cnt==0); // Assertion failed!
    cin >> n;
    for(i=1;i<=n;++i)
    {
        l=0;
        j=i;
        while(j!=0)
        {
            arr[l++]=j%10;
            j/=10;
        }
        c=1;
        r=arr[1]-arr[0];
        for(j=1;j<l-1;++j)
        {
            if(r!=arr[j+1]-arr[j])
            {
                c=0;
                break;
            }
        }
        cnt+=c;
    }
    cout << cnt;
    return 0;
}
