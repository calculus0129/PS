#include <bits/stdc++.h>
#define INF 25001
#define FOR for(int fi=0;fi<10;++fi) for(int fj=0;fj<10;++fj) for(int fk=0;fk<10;++fk)
using namespace std;


int normaldist(int x, int y)
{
    return (x<y)?((y-x)<=5?y-x:10-y+x):((x-y)<=5?x-y:10-x+y);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, tmp[10][10][10], d[10][10][10];
    FOR d[fi][fj][fk]=INF;
    cin >> n;
    int T, tT;
    cin >> tT;
    d[tT][0][0]=d[0][tT][0]=d[0][0][tT]=normaldist(0, tT);
    while(--n)
    {
        cin >> T;
        if(T==tT) continue;
        memcpy(tmp, d, sizeof(tmp));
        FOR d[fi][fj][fk]=INF;
        FOR {
            if(tmp[fi][fj][fk]==INF) continue;
            d[fi][fj][T]=min(d[fi][fj][T], tmp[fi][fj][fk]+normaldist(T, fk));
            d[fi][T][fk]=min(d[fi][T][fk], tmp[fi][fj][fk]+normaldist(T, fj));
            d[T][fj][fk]=min(d[T][fj][fk], tmp[fi][fj][fk]+normaldist(T, fi));
        }
        tT=T;
    }
    int ans=INF;
    FOR if(ans>d[fi][fj][fk]) ans = d[fi][fj][fk];
    cout << ans;

    return 0;
}
