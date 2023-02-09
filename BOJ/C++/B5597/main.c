#include <stdio.h>

int main()
{
    int a[31]={}, n, r=0;
    for(int i=0;i<28;++i)
    {
        scanf("%d", &n);
        ++a[n];
    }
    for(int i=1;i<=30;++i)
    {
        if(!a[i])
        {
            if(r)
            {
                printf("\n%d", i);
                break;
            }
            printf("%d", i);
            ++r;
        }
    }

    return 0;
}
