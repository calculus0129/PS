#include <stdio.h>
int main() {
    int a, b, c, la, lb, lc;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &la, &lb, &lc);
    int s = (a*60+b)*60+c, ls = (la*60+lb)*60+lc;
    if(s>ls) ls += 86400;
    int ans = ls - s;
    printf("%02d:%02d:%02d", ans/3600, ans/60%60, ans%60);

    return 0;
}