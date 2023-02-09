#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<vector<int>> q, nxt_q;
    vector<int> f, h(3, 0), nxt(3,0), dmgs[6] = {
        {9,3,1},
        {9,1,3},
        {3,9,1},
        {3,1,9},
        {1,9,3},
        {1,3,9},
    };
    //assert(h[2]==0); // is the vector initialized well?
    bool checked[61][61][61]={};
    //assert(checked[13][49][21]==0); // is it initialized well?
    int n, cnt=0;

    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;++i) cin >> h[i];

    checked[h[0]][h[1]][h[2]] = 1;

    nxt_q.push(h);

    while(!checked[0][0][0]) {
        ++cnt;
        swap(q, nxt_q);
        while(!q.empty())
        {
            f = q.front(); q.pop();
            for(vector<int> d : dmgs) {
                nxt[0] = max(0, f[0]-d[0]);
                nxt[1] = max(0, f[1]-d[1]);
                nxt[2] = max(0, f[2]-d[2]);
                if(!checked[nxt[0]][nxt[1]][nxt[2]]) {
                    checked[nxt[0]][nxt[1]][nxt[2]]=1;
                    nxt_q.push(nxt);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
