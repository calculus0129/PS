#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int cnt=0;
    for(auto i=s.begin();i!=s.end();++i)
    {
        if(*i<'D') cnt+=3;
        else if(*i<'G') cnt+=4;
        else if(*i<'J') cnt+=5;
        else if(*i<'M') cnt+=6;
        else if(*i<'P') cnt+=7;
        else if(*i<'T') cnt+=8;
        else if(*i<'W') cnt+=9;
        else cnt+=10;
    }
    cout << cnt;
    return 0;
}
