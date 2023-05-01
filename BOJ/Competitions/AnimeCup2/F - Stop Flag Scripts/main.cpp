#include <bits/stdc++.h>
typedef long long int LLI;
using namespace std;

int main()
{
    int c=0;
    cin.tie(0)->sync_with_stdio(0);
    LLI n, k, ans=0, a, b=0;
    cin>>n>>k;
    vector<LLI> p(n, 0), t(n, 0);
    for(int i=0;i<n;++i) cin >> p[i];
    for(int i=0;i<n;++i) cin >> t[i];
    for(int i=0;i<n;++i,b-=c) {
        b-=c;
        p[i]+=c;
        if(i<k)
        {

        }
        if(p[i]<t[i])
        {
            p[i]=t[i]-p[i];
            a = p[i]/k + (p[i]%k!=0);
            c+=a;
            b+=a*k;
        }
        if(i>=k)
        {

        }
        /// because of timeout, have to arrange the 'adding' operation in this loop to be O(1).
        /// Not finished, YET.
    }
    cout << ans;
    // fail...
    return 0;
}

/*
7 13
0 0 0 0 0 0 0
1 2 3 4 5 6 7
=>1

7 13
0 0 0 0 0 0 0
1 2 3 4 5 6 8
=>2

7 13
0 0 0 0 0 0 1
1 2 3 4 5 6 8
=>1

7 13
1 2 3 4 5 6 7
1 2 3 4 5 6 7
=>0

7 1
0 0 0 0 0 0 0
0 0 0 0 0 0 1
=>1

7 1
1 0 0 0 0 0 0
0 0 0 0 0 0 0
=> 0

7 1
0 0 0 0 0 0 0
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
=>7000000000

7 2
0 0 0 0 0 0 0
6 7 4 1 0 0 0
=> 6

7 2
0 0 0 0 0 0 0
5 7 3 0 0 0 0
=> 6

7 2
0 0 0 0 0 0 0
7 7 2 2 0 0 0
=> 7

*/
