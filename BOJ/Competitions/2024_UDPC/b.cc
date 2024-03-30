#include <bits/stdc++.h>
using namespace std;

int work2(int x) {
    if(x <=2 ) return 4-x;
    if(x == 5) return 3;
    int ret = 0;
    while(x%4 != 0) {
        ++ret;
        x-=3;
    }
    ret += x/4;
    return ret;
}

int work(int a, int b) {
    int ret = 0;
    if(4*a < b) {
        b -= 4*a;
        ret = work2(b);
        for(int i=1;i<=a;++i) {
            ret = min(ret, work2(b+i));
        }
        return ret;
    }
    else if(3*a > b) {
        return 3*a-b;
    }
    else return 0;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t, a, b; cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << work(a, b) << '\n';
    }
    
    return 0;
}