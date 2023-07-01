#include <bits/stdc++.h>
int e[200001], a[200001], T, n, y[200001], x[200001]; // arr[200001], 
using namespace std;

void work() {
    int i, j;
    for(i=1;i<=n;++i) {
        j=lower_bound(e, e+i, a[i])-e;
        if(e[j]==a[i] || j==i) --j;
        e[i]=max(e[j]+T, a[i]);
        //for(k=j+1;k<=i;++k) ++arr[k]; // 문제
        x[i]=i;
        y[i]=j;
    }
}

int main() {
    int i, t, ans;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> T;
    for(i=1;i<=n;++i) cin >> a[i];
    sort(a+1, a+n+1);
    work();
    ans = (lower_bound(y+1, y+n+1, 1)-y)-(lower_bound(x+1, x+n+1, 1)-x);
    for(i=2;i<=n;++i) {
        t = (lower_bound(y+1, y+n+1, i)-y)-(lower_bound(x+1, x+n+1, i)-x);
        ans = max(ans, t);
    }
    cout << ans;
    //cout << *max_element(arr+1, arr+n+1);
    return 0;
}

/*
#include <bits/stdc++.h>
int arr[200001], s[200001], e[200001], a[200001], T, n;
using namespace std;

void work() {
    int i, j, k;
    for(i=1;i<=n;++i) {
        j=lower_bound(e, e+i, a[i])-e;
        if(e[j]==a[i] || j==i) --j;
        e[i]=(s[i]=max(e[j], a[i]-T)+1)+T-1;
        for(k=j+1;k<=i;++k) ++arr[k];
    }
}

int main() {
    int i, j;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> T;
    for(i=1;i<=n;++i) cin >> a[i];
    sort(a+1, a+n+1);
    work();
    cout << *max_element(arr+1, arr+n+1);
    return 0;
}
*/