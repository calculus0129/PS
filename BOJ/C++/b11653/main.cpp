#include <bits/stdc++.h>
using namespace std;
vector<int> primes={2,3,5,7}, factors;

void solveprimes()
{
    /// 10000 미만의 소수를 구해서 primes에 저장.
    for(int p=11,r=1,i;p<10000;p+=2,r=1)
    {
        for(i=primes.size()-1;i>0;--i)
        {
            if(p%primes[i]==0)
            {
                r=0;
                break;
            }
        }
        if(r)
        {
            primes.push_back(p);
        }
    }
}

void factorize(int n)
{
    for(int i=0,e=primes.size(),p=2,s=sqrt(n);i<e && p<=s;)
    {
        if(n%p==0)
        {
            n/=p;
            factors.push_back(p);
        }
        else
        {
            p=primes[++i];
        }
    }
    if(n!=1)
    {
        factors.push_back(n);
    }
}

int main()
{
    primes.reserve(10001);
    solveprimes();
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    factorize(n);
    for(int i=0,e=factors.size();i<e;++i)
    {
        cout << factors[i] << "\n";
    }
    return 0;
}
