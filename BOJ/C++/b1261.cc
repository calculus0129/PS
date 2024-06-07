#include <bits/stdc++.h>
#define CHECK(x,y) (x)>=0 && (x)<m && (y)>=0 && (y)<n
using namespace std;
bool miro[101][101], discovered[101][101];
int m, n;
typedef pair<int, int> pii;

int dir[][2] = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};

int discover() {
    queue<pii> q0, q1;
    queue<pii> &que=q0, &tmp=q1;
    que.push({0,0});
    discovered[0][0] = true;
    int ret = -1;
    do {
        ++ret;
        while(!que.empty()) {
            pii t = que.front(); que.pop();
            int a=t.first, b = t.second, na, nb, i;
            for(i=0;i<4;++i) {
                na = a+dir[i][0], nb = b+dir[i][1];
                if(CHECK(na, nb) && !discovered[na][nb]) {
                    discovered[na][nb] = true;
                    if(miro[na][nb]) {
                        tmp.push({na, nb});
                    } else {
                        que.push({na, nb});
                    }
                }
            }
        }
        swap(que, tmp);
    } while(!discovered[m-1][n-1]);
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    string s;
    for(int i=0, j;i<m;++i) {
        cin >> s;
        j=0;
        for(char const *c=s.c_str();*c!='\0';++c) {
            miro[i][j++] = *c == '1';
        }
    }
    cout << discover();

    return 0;
}