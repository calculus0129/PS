#include <stdio.h>

double f(int arr[1001], int n)
{
    double fr=0.0f,avg=0.0f;
    for(int i=0;i<n;++i) avg+=arr[i];
    avg/=n;
    for(int i=0;i<n;++i)
    {
        if(arr[i]>avg)
        {
            ++fr;
        }
    }
    fr = fr*100.0f/n;
    return fr;
}

int main()
{
    int t, n, arr[1001]={};
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d", &arr[i]);
        }
        printf("%.3f%%\n", f(arr, n));
    }
}
