#include <stdio.h>

int main()
{
    int arr[6], i, brr[6]={1,1,2,2,2,8};
    for(i=0;i<6;++i)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<6;++i)
    {
        printf("%d ", brr[i]-arr[i]);
    }

    return 0;
}
