#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int D[MAX+1], A[MAX+2], AA[MAX+1];
int main() {
    AA[0] = -1000000001; // -2147483648
    int n, i=1, x, siz=0, d;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; while(i<=n) cin >> A[i++];
    for(i=1;i<=n;++i) {
        D[i] = lower_bound(AA, AA+siz+1, A[i])-AA;
        AA[D[i]] = A[i];
        if(D[i]>siz) ++siz;
    }
    vector<int> v;
    A[x=n+1]= 1000000001; // (1<<31) == -2147483648; (1<<30) (1<<30) (int)1073741824
    for(i=n,d=siz;i>0&&d>0;--i) if(D[i] == d && A[i]<A[x]) {
        v.push_back(A[x=i]); --d;
    }
    cout << siz << '\n';
    for(auto k=v.rbegin(), e=v.rend();k!=e;++k) cout << *k << ' ';
    return 0;
}