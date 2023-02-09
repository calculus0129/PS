#include <stdio.h>
#include <string.h>
#define MAX 3001 /// in boj 300001

int main()
{
    int n, arr[MAX], c=1, l=0;
    char s[MAX], r;
    scanf("%d", &n);
    scanf("%s", s);
    r=s[0];
    for(int i=1,e=strlen(s);i<e;++i)
    {
        if(s[i]==r)
        {
            ++c;
        }
        else
        {
            arr[l++]=c;
            r=s[i];
            c=1;
        }
    }
    arr[l++]=c;
    c=0;

    for(int i=1,m;i<l;++i)
    {
        m = (arr[i-1]<arr[i])?arr[i-1]:arr[i];
        if(m>c)
        {
            c = m;
        }
    }
    printf("%d", c<<1);

    return 0;
}
