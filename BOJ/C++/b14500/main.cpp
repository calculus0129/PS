#include <bits/stdc++.h>
using namespace std;
struct tetromino {
    int r, c, shape[4][4];
};
int main()
{
    tetromino tetrominoes[7] =
    {
        { 1,4, {
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
        }},

        { 2,3, {
            {1,1,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        }},

        { 2,2, {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0},
        }},

        { 3,2, {
            {1,1,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {0,0,0,0},
        }},

        { 3,2, {
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0},
        }},

        { 3,2, {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0},
        }},

        { 3,2, {
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0},
        }},
    };

    int arr[4][50][50]={{{}}}, siz[4][2]={{}}; // 510 in BOJ!
    cin.tie(0)->sync_with_stdio(0);
    int msum=0, s1, s2;
    cin >> s1 >> s2;
    for(int i=0,j;i<s1;++i) for(j=0;j<s2;++j) cin >> arr[0][i][j];
    for(int i=0,j;i<s1;++i) for(j=0;j<s2;++j)
    {
        arr[1][j][i]=arr[2][s1-1-i][s2-1-j]=arr[3][s2-1-j][s1-1-i]=arr[0][i][j];
    }
    siz[1][1]=siz[2][0]=siz[3][1]=siz[0][0]=s1;
    siz[1][0]=siz[2][1]=siz[3][0]=siz[0][1]=s2;
    for(int i=0,j,k,l,o,p,sum;i<4;++i) for(j=0;j<7;++j)
    {
        for(k=0;k+tetrominoes[j].r<=siz[i][0];++k) for(l=0;l+tetrominoes[j].c<=siz[i][1];++l) {
            sum=0;
            for(o=0;o<4;++o) for(p=0;p<4;++p)
            {
                sum += tetrominoes[j].shape[o][p] * arr[i][k+o][l+p];
            }
            msum = max(msum, sum);
        }
    }
    cout << msum;
    return 0;
}
