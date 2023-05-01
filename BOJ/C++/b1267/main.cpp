#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a, n, y=0, m=0;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a;
        y += (1+a/30)*10;
        m += (1+a/60)*15;
    }
    if(y<m) cout << "Y " << y;
    else if (y>m) cout << "M " << m;
    else cout << "Y M " << y;

    return 0;
}
