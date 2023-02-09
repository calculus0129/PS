#include <stdio.h>
#include <string.h>

int main()
{
    long long arr[15][15];//={{}};
    ///assert(arr[0][0]==arr[14][14]==0LL); // assertion failed..
    memset(arr, 0, sizeof(arr));
    for(int i=1;i<15;++i)
    {
        arr[0][i]=(long long)i;
    }
    for(int i=1;i<15;++i) for(int j=1;j<15;++j)
    {
        arr[i][j]=arr[i-1][j]+arr[i][j-1];
    }

    //Debug
    /*
    for(int i=0;i<15;++i)
    {
        for(int j=1;j<15;++j)
        {
            printf("%lld ", arr[i][j]);
        }
        puts("");
    }*/
    //37442160: 14 14
    int t, k, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &k, &n);
        printf("%lld\n", arr[k][n]);
    }
    return 0;
}
