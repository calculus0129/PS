#include <bits/stdc++.h>
using namespace std;
//#define BIG (4294967296LL*4294967296LL)
#define LLI long long int
using namespace std;

// defining class of 2x2 symmetric matrix ( (a1, a2), (a2, a3) )
class mat {
public:
    LLI a1, a2, a3, a4;
    //mat();
    mat(LLI a1, LLI a2, LLI a3, LLI a4)
    : a1(a1), a2(a2), a3(a3), a4(a4) {}
    mat operator*(const mat &other);
    void operator*=(const mat &other);
};

mat mat::operator*(const mat &other)
{
    LLI b1, b2, b3, b4;
    b1 = (a1*other.a1 + a2*other.a3);
    b2 = (a1*other.a2 + a2*other.a4);
    b3 = (a3*other.a1 + a4*other.a3);
    b4 = (a3*other.a2 + a4*other.a4);
    return mat(b1, b2, b3, b4);
}

void mat::operator*=(const mat &other)
{
    LLI b1, b2, b3, b4;
    b1 = (a1*other.a1 + a2*other.a3);
    b2 = (a1*other.a2 + a2*other.a4);
    b3 = (a3*other.a1 + a4*other.a3);
    b4 = (a3*other.a2 + a4*other.a4);
    a1=b1;
    a2=b2;
    a3=b3;
    a4=b4;
}

int main()
{
    LLI n, A=0LL, B=0LL;
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    vector<LLI> arr(n, 0LL);
    for(LLI i=0;i<n;++i)
    {
        cin >> arr[i];
    }
    for(auto i:arr)
    {
        mat m(-1LL, -1LL, 1LL, 0LL), res(1LL, 0LL, 0LL, 1LL);
        n=i;
        while(n)
        {
            if(n&1)
            {
                res *= m;
            }
            m *= m;
            n>>=1;
        }
        A+=res.a3;
        B+=res.a4;
    }
    cout << A << " " << B;
    return 0;
}
