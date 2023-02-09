#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%.0f", ceil((-3+sqrt(9+(long long)12*(n-1)))/6)+1);
    return 0;
}
