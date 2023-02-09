#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, n, x;
    scanf("%d", &x);
    n = ceil((-1+sqrt(1+8*x))/2);
    a=x-n*(n-1)/2, b=n+1-a;
    if(n&1)
    {
        printf("%d/%d", b, a);
    }
    else
    {
        printf("%d/%d", a, b);
    }
    return 0;
}
