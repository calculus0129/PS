#include <stdio.h>

int main()
{
    char *s, c;
    s = fgets(&c, 1, stdin);
    while(s != NULL)
    {
        printf("%c", c);
        s = fgets(&c, 1, stdin);
    }
    return 0;
}
