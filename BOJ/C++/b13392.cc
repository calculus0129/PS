#include <bits/stdc++.h>
using namespace std;

vector<int> Prev(10);
int ldist(char src, char dst) {
    src-='0';
    dst-='0';
    int ret = 0;
    while(src%10 != dst) {
        ++src;
        ++ret;
    }
    return ret;
}

int rdist(char src, char dst) {
    src-='0'-10, dst-='0';
    int ret = 0;
    while(src%10 != dst) {
        --src;
        ++ret;
    }
    return ret;
}

char turn(char src, int add) {
    return '0'+(src-'0'+add+10)%10;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string w, s;
    cin >> w >> s;
    for(int i=0;i<10;++i) Prev[i] = min(ldist(i+'0', s[n-1]), rdist(i+'0', s[n-1]));
    for(int i=2,j,l0,l1,k;i<=n;++i) {
        vector<int> tmp(10, INT_MAX);
        for(j=0;j<10;++j) {
            l0 = j+'0';
            l1 = turn(w[n-i+1], ldist(w[n-i], j+'0'));
            for(k=0;k<10;++k) {
                tmp[j] = min(tmp[j], k+rdist(l0, s[n-i])+Prev[l1-'0']);
                l0 = turn(l0, 1);
                l1 = turn(l1, 1);
            }
        }
        Prev = tmp;
    }
    cout << Prev[w[0]-'0'];

    return 0;
}