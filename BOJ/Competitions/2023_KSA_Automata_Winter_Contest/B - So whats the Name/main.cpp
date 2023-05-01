#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    char s[300001];
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    cin >> s;
    int cnt=0;
    int n_last_a[2]={}, tmp_last_a[2]={-1,-1};
    int n_last_ja=-1, tmp_last_ja=-1;
    /*
    for(int i=0;i<n;++i)
    {
        if(s[i]=='A' && cnt<2)
        {
            n_last_a[cnt++]=i;
            if(cnt==2) tmp_last_a[0]=i;
        }
        else if(s[i]=='A')
        {
            if(tmp_last_a[1]==-1) tmp_last_a[1]=i;
            else {
                tmp_last_a[0]=tmp_last_a[1];
                tmp_last_a[1]=i;
            }
        }
        else if(tmp_last_a[1]!=-1 && cnt==2 && s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
        {
            if(n_last_ja==-1)
            {
                n_last_ja=i;
            }
            else tmp_last_ja=i;
            if(n_last_ja-n_last_a[0] > tmp_last_ja - tmp_last_a[0])
            {
                n_last_a[0]=tmp_last_a[0];
                tmp_last_a[0]=n_last_a[1]=tmp_last_a[1];
                n_last_ja = tmp_last_ja;
                tmp_last_ja=tmp_last_a[1]=-1;
            }
        }
    }
    */
    if (s[n-3]!='A' || s[n-2]!='A' || s[n-1]=='A' || s[n-1]=='E' || s[n-1]=='I' || s[n-1]=='O' || s[n-1]=='U')//(cnt<2 || n_last_ja==-1 || n-n_last_ja+n_last_a[0]+2 < m)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << s;
        //for(int i=0;i<m-3;++i) cout << s[i];
        //cout << "AA";
        //cout << s[n_last_ja];
    }

    /// Only Solved Partially

    return 0;
}
