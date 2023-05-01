// This is actually b1011!
#include <iostream>
#include <cmath>
typedef long long int LLI;
using namespace std;

LLI f(int x, int y)
{
    LLI d = y-x;
    LLI n = sqrt(d);
    if (n*(n+1)>=d) n--;
    return 1LL+(n<<1LL)+((n+1LL)*(n+1LL)<d?1LL:0LL);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int x, y, t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << f(x, y) << endl;
    }
    return 0;
}
