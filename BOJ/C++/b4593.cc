#include <bits/stdc++.h>
using namespace std;
char a[76], b[76];

char win[][2] = {
    {'S', 'R'},
    {'R', 'P'},
    {'P', 'S'},
};

int decision(char c, char d) {
    if(c == d) return 0;
    for(int i=0;i<3;++i) if(win[i][0] == c && win[i][1] == d) return -1;
    return 1;
}

void countwin() {
    int p1=0, p2=0;
    for(int i=0, e=strlen(a), d;i<e;++i) {
        d = decision(a[i], b[i]);
        p1 += max(0, d);
        p2 += max(0, -d);
    }
    cout << "P1: " << p1 << '\n';
    cout << "P2: " << p2 << '\n';
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a;
    cin >> b;
    // int n;
    while(a[0] != 'E') {
        // n = strlen(a);
        // cout << "length: " << n << '\n';
        countwin();
        cin >> a;
        cin >> b;
    }
    return 0;
}