#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    char n[8];
    vector<int> vec(10,0);
    cin>>n;
    for(int i=0,e=strlen(n),a;i<e;++i)
    {
        a=n[i]-'0';
        if(a==9) a=6;
        ++vec[a];
    }
    vec[6]=(vec[6]+1>>1);
    cout << *max_element(vec.begin(), vec.end());
    return 0;
}
