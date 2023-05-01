#include <iostream>
using namespace std;

int main()
{
    int n;
    size_t len, l;
    int k;
    bool flag=false;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> len;
    for(l=len;l<=100;++l)
    {
        k = 2*n-l*(l-1);
        if(k<0) break;
        if(k%(l<<1)==0)
        {
            flag = true;
            k /= (l<<1);
            break;
        }
    }
    if(flag)
    {
        for(size_t i=0;i<l;++i)
        {
            cout << k+i << " ";
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}
