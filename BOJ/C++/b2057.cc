#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

/*
x!=1,000,000,000,000,000,000 for the first time is 
x=20. The value of 20! is 2,432,902,008,176,640,000. (within lli range!)
*/

lli rangeFactorial(lli n, lli mx=19LL) {
    lli m = 1LL, ret = 0LL;
    while(ret<=mx && m<=n) {
        m *= ++ret;
    }
    return ret-1LL;
}
lli fact(lli n) {
    lli ret = 1LL;
    while(n>0LL) ret *= n--;
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    lli n;
    cin >> n;
    if(n==0LL) {
        cout << "NO";
        return 0;
    }
    lli num = rangeFactorial(n);
    while(n>0LL && num>=0) {
        n-=fact(num);
        num=rangeFactorial(n, num-1);
    }
    cout << (n==0LL?"YES":"NO");

    return 0;
}