#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> primes;
    int m, n, sum=0;
    scanf("%d%d", &m, &n);
    m = max(2, m);
    if(m==2 && n>1)
    {
        primes.push_back(2);
        ++m;
    }
    for(int i=m, r=1;i<=n;++i, r=1)
    {
        if(!(i&1)) continue;
        for(int j=3;j<(i>>1);j+=2)
        {
            if(i%j==0)
            {
                r=0;
                break;
            }
        }
        if(r)
        {
            primes.push_back(i);
        }
    }
    if(primes.size()==0)
    {
        printf("-1");
    }
    else
    {
        for(int i=primes.size()-1;i>=0;--i)
        {
            sum+=primes[i];
        }
        printf("%d\n%d", sum, primes[0]);
    }

    return 0;
}
