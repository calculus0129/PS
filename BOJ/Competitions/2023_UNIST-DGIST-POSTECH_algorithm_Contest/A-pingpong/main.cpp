#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int f=0, n, A[2]={};
    cin >> n;
    char c;
    for(int i=0, r;i<n;++i)
    {
        cin >> c;
        if(!f)
        {
            r = c!='D';
            A[r]++;
            if(A[r]>A[r^1]+1)
            {
                f=1;
            }
        }
    }
    cout << A[0] << ":" << A[1];
    return 0;
}
