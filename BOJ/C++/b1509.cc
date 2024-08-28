// https://yabmoons.tistory.com/592
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome[2501][2501];
int minPartition[2501];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    char s[2501]; cin >> s;
    int n = strlen(s);
    for(int i=0;i<n;++i) {
        isPalindrome[i][i] = true;
        if(i+1<n) isPalindrome[i][i+1] = s[i]==s[i+1];
    }
    for(int i=2,j;i<n;++i) for(j=i-2;~j;--j) isPalindrome[j][i] =  isPalindrome[j+1][i-1] && s[j]==s[i];
    for(int i=0,j,bef=1;i<n;++i,++bef) {
        for(j=0;j<i;++j) if(isPalindrome[j][i]) bef = min(bef, minPartition[j]+1);
        minPartition[i+1] = bef;
    }
    cout << minPartition[n];
    
    return 0;
}