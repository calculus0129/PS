#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, arr[50]={}, s=0;
    double m;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0,j,c;i<n;++i)
    {
        c=0;
        j=i-1;
        if(j>=0)
        {
            ++c;
            m=(arr[j]-(double)arr[i])/(i-(double)j);
            for(j=i-2;j>=0;--j)
            {
                if(m<(arr[j]-(double)arr[i])/(i-(double)j))
                {
                    m = (arr[j]-(double)arr[i])/(i-(double)j);
                    ++c;
                }
            }
        }
        j=i+1;
        if(j<n)
        {
            ++c;
            m=(arr[j]-(double)arr[i])/((double)j-i);
            for(j=i+2;j<n;++j)
            {
                if(m<(arr[j]-(double)arr[i])/((double)j-i))
                {
                    m = (arr[j]-(double)arr[i])/((double)j-i);
                    ++c;
                }
            }
        }
        if(s<c)
        {
            s=c;
        }
    }
    cout << s;
    return 0;
}
