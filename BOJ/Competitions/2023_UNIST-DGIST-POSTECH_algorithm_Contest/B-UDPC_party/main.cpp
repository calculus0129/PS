#include <iostream>
using namespace std;
int main()
{
    int A[2]={};
    string s;
    cin >> s;
    for(int i=0, e=s.size();i<e;++i)
    {
        A[s[i]=='D' || s[i]=='P']++;
    }
    if(A[0]>(A[1]+1>>1))
    {
        cout << "U";
    }
    if(A[1]>0)
    {
        cout << "DP";
    }
    return 0;
}
