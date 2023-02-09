#include <bits/stdc++.h>
#define BIG 1000000007
#define LLI long long int
using namespace std;

// defining class of 2x2 symmetric matrix ( (a1, a2), (a2, a3) )
class mat {
public:
    LLI a1, a2, a3;
    //mat();
    mat(LLI a1, LLI a2, LLI a3)
    : a1(a1), a2(a2), a3(a3) {}
    mat operator*(const mat &other);
    void operator*=(const mat &other);
};

mat mat::operator*(const mat &other)
{
    LLI b1, b2, b3;
    b1 = (a1*other.a1%BIG + a2*other.a2%BIG)%BIG;
    b2 = (a1*other.a2%BIG + a2*other.a3%BIG)%BIG;
    b3 = (a2*other.a2%BIG + a3*other.a3%BIG)%BIG;
    return mat(b1, b2, b3);
}

void mat::operator*=(const mat &other)
{
    LLI b1, b2, b3;
    b1 = (a1*other.a1%BIG + a2*other.a2%BIG)%BIG;
    b2 = (a1*other.a2%BIG + a2*other.a3%BIG)%BIG;
    b3 = (a2*other.a2%BIG + a3*other.a3%BIG)%BIG;
    a1=b1;
    a2=b2;
    a3=b3;
}

int main()
{
    LLI n;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    mat fibo(1LL, 1LL, 0LL), res(1LL, 0LL, 1LL);
    while(n)
    {
        if(n&1)
        {
            res *= fibo;
        }
        fibo *= fibo;
        n>>=1;
    }
    cout << res.a2;
    return 0;
}
