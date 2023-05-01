#include <iostream>
#include <string>
using namespace std;

string combo[101][101];

string add(string s1, string s2) {
    string ret = "";
    while(s1.length()>s2.length()) s2 = '0' + s2;
    while(s2.length()>s1.length()) s1 = '0' + s1;
    int l = s1.length();
    int sum = 0;
    for(int i=l-1;i>=0;i--) {
        sum+=(s1[i]-'0')+(s2[i]-'0');
        ret = to_string(sum%10)+ret;
        sum/=10;
    }
    if(sum) ret = "1"+ret;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, r;
    for(int i=0;i<=100;++i) combo[i][0]=combo[0][i]="1";
    for(int i=1,j;i<100;++i) for(j=1;i+j<=100;++j) combo[i][j] = add(combo[i-1][j],combo[i][j-1]);
    cin>>n>>r;
    cout<<combo[n-r][r];

    return 0;
}
