#include <bits/stdc++.h>
#define MAX 150 // 1500 in BOJ
using namespace std;
struct pos {int x, y;};
string arr[MAX];
int reached[MAX][MAX];
queue<pos> reachable, melting;
int m, n, Dir[4][2]={
    {1,0},{-1,0},{0,1},{0,-1}
};

void reach()
{
    pos f;
    int x,y,nx,ny,i;
    queue<pos> nxt_reach;
    while(!reachable.empty())
    {
        f = reachable.front();
        reachable.pop();
        x = f.x, y=f.y;
        for(i=0;i<4;++i)
        {
            nx = x + Dir[i][0], ny = y + Dir[i][1];
            if(nx<0||ny<0||nx>=m||ny>=n||reached[nx][ny]) continue;
            reached[nx][ny]=1;
            if(arr[nx][ny]=='.')
            {
                reachable.push({nx,ny});
            }
            else //if(arr[nx][ny]='X')
            {
                nxt_reach.push({nx,ny});
            }
        }
    }
    reachable=nxt_reach;
}

void melt()
{
    pos f;
    int x,y,nx,ny,i;
    queue<pos> nxt_melting;
    while(!melting.empty())
    {
        f = melting.front();
        melting.pop();
        x = f.x, y = f.y;
        for(i=0;i<4;++i)
        {
            nx = x + Dir[i][0], ny = y + Dir[i][1];
            if(nx<0||ny<0||nx>=m||ny>=n||arr[nx][ny]=='.') continue;
            /*if(arr[nx][ny]=='.')
            {
                //melting.push({nx,ny});
            }*/
            //else //if(arr[nx][ny]='X')
            //{
            arr[nx][ny]='.';
            nxt_melting.push({nx,ny});
            //}
        }
    }
    melting = nxt_melting;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>m>>n;
    int day=0, r=0;
    pos swans[2];
    for(int i=0,j;i<m;++i)
    {
        cin >> arr[i];
        for(j=0;j<n;++j)
        {
            if(arr[i][j]=='L')
            {
                swans[r++]={i,j};
                arr[i][j]='.';
            }
            if(arr[i][j]=='.')
            {
                melting.push({i,j});
            }
        }
    }
    reachable.push(swans[0]);
    reached[swans[0].x][swans[0].y]=1;
    reach();
    while(!reached[swans[1].x][swans[1].y])
    {
        ++day;
        melt();
        reach();
    }
    cout << day;
    return 0;
}

/*#include <bits/stdc++.h>
#define X first
#define Y second
#define MAX 150 // 1500 in BOJ
#define P pair<int,int>
using namespace std;
int r, c, mov[4][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};
queue<P> ice;
vector<P> reachable;

int arr[MAX][MAX];

void reach(P p)
{
    int x=p.X,y=p.Y,nx,ny;
    arr[x][y] = -1;
    for(int * m : mov)
    {
        nx=x+m[0],ny=y+m[1];
        if(nx<0||ny<0||nx>=r||ny>=c||arr[nx][ny]==-1) continue;
        if(arr[nx][ny]==0) reach({nx,ny});
    }
}

void reaching() // -1 spreads through 0... or reached==1 is spread through nearby reach[i][j] if arr[i][j] == 0
{
    P p;
    vector<P> tmp;
    swap(tmp, reachable);
    while(!tmp.empty())
    {
        p=tmp.back();
        tmp.pop_back();
        if(arr[p.X][p.Y]==-1) continue;
        reach(p);
    }
}

void melt() // 1 goes to 0 and will be reached if it is near -1.
{
    queue<P> q;
    vector<P> toB0;
    swap(q, ice);
    int m,x,y,nx,ny;
    P f;
    while(!q.empty())
    {
        f = q.front();
        x=f.X,y=f.Y,m=1;
        q.pop();
        for(int * i : mov)
        {
            nx=x+i[0],ny=y+i[1];
            if(nx<0||ny<0||nx>=r||ny>=c) continue;
            if(arr[nx][ny]<m) m=arr[nx][ny];
        }
        if(m==1)
        {
            ice.push(f);
            continue;
        }
        toB0.push_back({x,y});//arr[x][y]=0;
        if(m==-1) reachable.push_back(f);
    }
    for(P p : toB0)
    {
        arr[p.X][p.Y]=0;
    }
}

int main()
{
    int day=0, m=0;
    P init, term;
    char s[MAX+1];
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    for(int i=0,j;i<r;++i)
    {
        cin >> s;
        for(j=0;j<c;++j)
        {
            switch(s[j])
            {
            case 'X':
                arr[i][j]=1;
                ice.push(P({i,j}));
                break;
            case 'L':
                if(!m)
                {
                    m=1;
                    init = P({i,j});
                    //reachable.push_back(init);
                }
                else
                {
                    term = P({i,j});
                }
            }
        }
    }
    reach(init);
    while(arr[term.X][term.Y]!=-1)
    {
        ++day;
        melt();
        reaching();
    }
    cout << day;

    return 0;
}
*/
