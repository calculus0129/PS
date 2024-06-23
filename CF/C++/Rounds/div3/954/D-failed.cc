#include <bits/stdc++.h>
using namespace std;

int ans, n;
char s[21];

void mini_work() {
    if(n<=2) {
        sscanf(s, "%2d", &ans);
    } else {
        if(s[0] == '0' || s[2] == '0') ans = 0;
        else if(s[0]<s[1]) {

        }
        else {
            ans = (s[0]-'0')+(s[1]-'0')+(s[2]-'0') + 9*min(s[0]-'0', s[1]-'0');
        }
    }
}

void general_work() {
    if(strstr(s, "0")!=NULL) ans = 0;
    else {
        for(int i=0;i<n;++i) ans += s[i]-'0';
        ans += (*max_element(s, s+n)-'0')*9;
    }
}

void work() {
    memset(s, 0, sizeof(s));
    ans = 0;
    scanf("%d", &n);
    scanf("%s", s);
    if(n<=3) {
        mini_work();
    }
    else {
        general_work();
    }
    printf("%d\n", ans);
}

int main() {
    // cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    while(t--) {
        work();
    }
    return 0;
}

/**
Input
18
2
10
2
74
2
00
2
01
3
901
3
101
5
23311
6
987009
7
1111111
20
99999999999999999999
20
00000000000000000000
4
0212
18
057235283621345395
4
1112
20
19811678487321784121
4
1121
4
2221
3
011

Output
10
74
0
1
9
1
19
0
11
261
0
0
0
12
93
12
24
0
 */
// Solution Discussion: https://www.youtube.com/watch?v=SK27QUGO4bo