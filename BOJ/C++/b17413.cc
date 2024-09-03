#include <bits/stdc++.h>
using namespace std;
char s[101010], res[101010];

void process(int l, int r) {
    for(int i=l;i<=r;++i) {
        res[i] = s[r+l-i];
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    fgets(s, INT_MAX, stdin);
    s[strlen(s)-1]='\0';
    int n = strlen(s);
    bool isTag=false;
    for(int i=0,l=-1,r;i<=n;++i) {
        if(i == n) {
            if(l!=-1) process(l, r);
        }
        else if(!isTag) {
            if(s[i]!=' ' && s[i]!='<') {
                if(l==-1) {
                    l=i;
                }
                r = i;
            } else {
                res[i] = s[i];
                if(l != -1) {
                    process(l, r);
                    l = -1;
                }
                if(s[i] == '<') {
                    isTag = true;
                }
            }
        } else {
            res[i] = s[i];
            isTag = s[i] != '>';
        }
    }
    cout << res;

    return 0;
}