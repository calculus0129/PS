#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, A[202020]={};
    cin >> n;
    int si=(n-1>>1);
    A[si]=n;
    for(int s=si-1,i=2;s>=0;--s,i+=2)
    {
        A[s]=i;
    }
    for(int s=si+1,i=1;s<n;++s,i+=2)
    {
        A[s]=i;
    }
    cout << "YES" << endl;
    for(int i=0;i<n;++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    if(n&1)
    {
        for(int s=1,e=n,r=1;s<=e;r^=1)
        {
            if(r)
            {
                cout << s++ << " ";
            }
            else
            {
                cout << e-- << " ";
            }
        }
    }
    else
    {
        for(int s=1,e=n,r=0;s<=e;r^=1)
        {
            if(r)
            {
                cout << s++ << " ";
            }
            else
            {
                cout << e-- << " ";
            }
        }
    }

    return 0;
}
