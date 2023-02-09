#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(b>=c)
    {
        printf("-1");
    }
    else
    {
        printf("%.0f", floor((double)a/(c-b)+1.0f));
    }
    return 0;
}
