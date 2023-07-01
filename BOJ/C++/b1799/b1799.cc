#include <bits/stdc++.h>
using namespace std;
int n, mp[11][11], ld[20], cnt;

void work(int step, int*ans) {
    if(step>2*n) {
        *ans = max(*ans, cnt);
        return;
    }
    ++cnt;
    for(int i=max(0, step-n-1)+1,e=min(step-1, n);i<=e;++i) {
        if(mp[i][step-i]==1 && ld[n+step-2*i]==0) {
            ld[n+step-2*i] = 1;
            work(step+2, ans);
            ld[n+step-2*i] = 0;
        }
    }
    --cnt;
    work(step+2, ans);
}

int main() {
    int i, j;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(i=1;i<=n;++i) for(j=1;j<=n;++j) cin >> mp[i][j];

    int ans1=0, ans2=0;
    work(2, &ans1);
    work(3, &ans2);
    cout << ans1+ans2;
    
    return 0;
}