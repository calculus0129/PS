#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    y=y<0;
    printf("%d", 1+(y<<1)+(y^x<0));
    return 0;
}
