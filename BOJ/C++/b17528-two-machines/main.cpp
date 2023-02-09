#include <bits/stdc++.h>
#define MAX 250//250*250
using namespace std;
int main()
{
    int n, ta[250], tb[250], arr[MAX+1][MAX+1]={}, s=250*250;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i) cin >> ta[i] >> tb[i];

    for(int i=0, j, k;i<n;++i) for(j=0;j<=MAX;++j) for(k=0;k<=MAX;++k) {
        if((j-ta[i]>=0 && arr[j-ta[i]][k]==i) || (k-tb[i]>=0 && arr[j][k-tb[i]]==i)) {
            arr[j][k] = i+1;
        }
    }
    for(int j=0, k;j<=MAX;++j) for(k=0;k<=MAX;++k) if (arr[j][k]==n) {
        s=min(s, max(j, k));
    }
    cout<<s;
    return 0;
}
