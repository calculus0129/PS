#include <stdio.h>

int main()
{
    /// Apply Green's Theorem.
    int i=6,k,a,b,x=0,area=0;
    scanf("%d", &k);
    while(i--)
    {
        scanf("%d%d", &a, &b);
        switch(a)
        {
        case 1:
            x+=b;
            break;
        case 2:
            x-=b;
            break;
        case 3:
            area -= x*b;
            break;
        case 4:
            area += x*b;
            break;
        }
    }
    printf("%d", k*area);
    return 0;
}
