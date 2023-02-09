#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,v;
    scanf("%d%d%d", &a, &b, &v);
    printf("%.0f", ceil((v-a)/(double)(a-b))+1.0f);
    return 0;
}
