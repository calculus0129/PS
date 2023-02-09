#include <bits/stdc++.h>
using namespace std;
char arr[9][10];
int n, r;
vector<pair<int,int>> vec;

bool check(int x, int y)
{
    char a = arr[x][y];
    int i, j, m=x-x%3, n=y-y%3; /// with respect to n, variable shadowing exists.
    for(i=0;i<9;++i)
    {
        if((a==arr[i][y] && i!=x) || (a==arr[x][i] && i!=y)) {
            return false;
        }
    }
    for(i=0;i<3;++i) for(j=0;j<3;++j)
    {
        if(a == arr[m+i][n+j] && !(m+i==x && n+j == y))
        {
            return false;
        }
    }
    return true;
}

void sudoku(int depth)
{
    if(depth == n)
    {
        r=1;
        return;
    }
    int x=vec[depth].first, y = vec[depth].second;
    char i='0';
    while(!r && ++i<='9')
    {
        arr[x][y] = i;
        if (check(x,y))
        {
            sudoku(depth+1);
        }
    }
    if(!r) arr[x][y]='0'; /// ²À ÇÊ¿ä!
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0,j;i<9;++i)
    {
        cin >> arr[i];
        for(j=0;j<9;++j) if(arr[i][j]=='0')
        {
            vec.push_back({i,j});
        }
    }
    n = vec.size();
    sudoku(0);
    for(int i=0;i<9;++i)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
