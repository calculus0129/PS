#include <bits/stdc++.h>
using namespace std;

int char2int(char c) {
    if('0'<=c && c<='9') return c - '0';
    else return c - 'A' + 10;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    char s[33]={0};
    int b, res=0;
    cin >> s >> b;
    for(int i=0,e=strlen(s);i<e;++i) {
        res = res*b + char2int(s[i]);
    }
    cout << res;

    return 0;
}