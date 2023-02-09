#include <stdio.h>

int main()
{
    int i=0,T, a, b;
    scanf("%d", &T);
    while(++i<=T)
    {
        scanf("%d%d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
    }
    return 0;
}
