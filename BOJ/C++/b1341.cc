#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char arr[61];
ll a, b;
// LATER!

void work() {
    int n=0;
    while(b>>n) n++;
    for(int i=n-1;i>=0;--i) {
        arr[n-1-i] = ((a & 1LL<<i)?'*':'-');
    }
}

bool check() {
    ll mul = 0LL, tot = 0LL;
    // int n = 0;
    // while(b>>n) n++;

    int i=0;
    while((b<<i) + tot < 1LL<<60) {
        if(1<<i & tot) {
            ++i;
            continue;
        }
        mul |= 1LL<<i;
        tot = mul*b;
        // cout << "mul: " << mul << '\n';
        if((tot&tot+1LL) == 0LL) {
            break;
        }
    }
    if((m+mul)*b < (1LL<<60) || ((mul*b)&(mul*b+1LL)) == 0LL) {
        a*=mul;
        b*=mul;
        cout << "a and b: " << a << ' ' << b;
        return true;
    } else {
        cout << "b*mul: " << b*mul << '\n';
        return false;
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> a >> b;
    if(a == 0LL || b == 1LL) arr[0] = a?'*':'-';
    else if(b >= (1LL<<60) || (b&1LL) == 0LL) arr[0] = -1;
    else {
        if(!check()) arr[0] = -1;
        else work();
    }
    if(arr[0] == -1) cout << -1;
    else cout << arr;
    
    return 0;
}