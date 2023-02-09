#include <stdio.h>

int main()
{
    int V[100]={}, a, x, y, r=0; // V: Visit
    scanf("%d", &a);
    while(!V[a])
    {
        ++V[a];
        x=a/10,y=a%10;
        a=y*10+(x+y)%10;
        ++r;
    }
    printf("%d", r);
    return 0;
}
