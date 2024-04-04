#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    int n, ans;
    while(t--) {
        scanf("%d", &n);
        if(n == 1) ans=0;
        else {
            ans = 1;
            for(int i=2,e=n>>1, j;i<=e;++i) {
                j=n;
                while(j%i==0) {
                    ++ans;
                    j/=i;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}