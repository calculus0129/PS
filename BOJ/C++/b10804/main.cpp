#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    vector<int> vec, stk;
    for(int i=1;i<=20;++i) vec.push_back(i);
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<10;++i)
    {
        cin>>a>>b;
        for(int j=a-1;j<b;++j)
        {
            stk.push_back(vec[j]);
        }
        for(int j=a-1;j<b;++j)
        {
            vec[j]=stk.back();
            stk.pop_back();
        }
    }
    for(int i=0;i<20;++i)
    {
        cout << vec[i] << " ";
    }
    return 0;
}
