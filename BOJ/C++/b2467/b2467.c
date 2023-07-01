#include <stdio.h>
#include <math.h>
int main() {
    int n, arr[100001], i;
    scanf("%d", &n);
    for(i=0;i<n;++i) scanf("%d", &arr[i]);
    int *p1=arr, *p2=arr+n-1, a = *p1+*p2, *a1=p1, *a2=p2;
    while(p1!=p2) {
        if(abs(*p1+*p2)<abs(a)) {
            a1=p1; a2=p2; a=*a1+*a2;
        }
        if(*p1+*p2<0) ++p1;
        else if(*p1+*p2==0) break;
        else --p2;
    }
    printf("%d %d", *a1, *a2);
    return 0;
}