#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >>n;
    int a[1010], d[1010];
    for(int i=0;i<n;++i) cin >>a[i];
    memset(d, 0, sizeof(int)*n);
    d[0]=1;
    int i=0;
    while(++i<n) {
        for(int j=0;j<i;++j)
            if(a[j]<a[i] && d[i]<d[j])
            {
                d[i]=d[j];
            }
        ++d[i];
    }
    cout << *max_element(d, d+n);
    return 0;
}
