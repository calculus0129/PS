#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, d, m;
    long long int c=0;
    cin>>n>>d;
    vector<int> vec(n);
    for(int i=0;i<n;++i)
    {
        cin>>vec[i];
    }
    m = max(0, *max_element(vec.begin(), vec.end())-d);
    for(int i=0;i<n;++i)
    {
        if(m<vec[i])
        {
            c+=vec[i]-m;
        }
    }
    cout << c;

    return 0;
}
