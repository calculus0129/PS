#include <bits/stdc++.h>
#define MAX 10000
using namespace std;
int main()
{
    double x[MAX+1]={}, y[MAX+1]={}, sum=0;
    int n;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i) cin >> x[i]>>y[i];
    x[n]=x[0],y[n]=y[0];
    for(int i=0;i<n;++i)
    {
        sum += (x[i]+x[i+1])*(y[i+1]-y[i])/2;
    }
    cout << fixed << setprecision(1) << abs(sum);
    return 0;
}
