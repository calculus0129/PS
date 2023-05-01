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
    b1 = (a1*other.a1 + a2*other.a2);
    b2 = (a1*other.a2 + a2*other.a3);
    b3 = (a2*other.a2 + a3*other.a3);
    return mat(b1, b2, b3);
}

void mat::operator*=(const mat &other)
{
    LLI b1, b2, b3;
    b1 = (a1*other.a1 + a2*other.a2);
    b2 = (a1*other.a2 + a2*other.a3);
    b3 = (a2*other.a2 + a3*other.a3);
    a1=b1;
    a2=b2;
    a3=b3;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;

    }
    /// unfinished
    return 0;
}
