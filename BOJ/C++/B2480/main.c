#include <stdio.h>

int max(int a, int b)
{
    return (a<b)?b:a;
}

int main()
{
    int A[7]={}, a, b, c, mx, r, i, price=1;
    scanf("%d%d%d", &a, &b, &c);
    ++A[a], ++A[b], ++A[c];
    for(i=2,r=A[1];i<7;++i) if(r<A[i]) r=A[i];
    switch(r)
    {
    case 1:
        mx=max(a, max(b, c));
        price=mx*100;
        break;
    case 3:
        price=10;
    default:
        for(i=1;i<6;++i)
        {
            if(A[i]==r) break;
        }
        price*=(1000+100*i);
    }

    printf("%d", price);
    return 0;
}
