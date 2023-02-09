#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a=(a+(b+c)/60)%24, b=(b+c)%60;
    // a=a+(b+c)/60%24 => 24가 나옴. 23 48 25 입력시.
    printf("%d %d", a, b);
    return 0;
}
