#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int r, c;
    int v1[51]={101,}, v2[51]={101,};
    cin >> r >> c;
    for(int i=1;i<=r;++i)
    {
        cin >> v1[i];
    }
    v2[1] = v1[r];
    for(int i=2;i<=c;++i)
    {
        cin >> v2[i];
    }
    r = min_element(v1+1, v1+r+1)-v1;
    c = min_element(v2+1, v2+c+1)-v2;
    cout << r << " " << c;

    return 0;
}
