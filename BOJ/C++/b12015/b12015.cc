#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int A[MAX+1], D[MAX+1], AA[MAX+1];
int main() {
    int n, i, j, siz=0, idx;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(i=1;i<=n;++i) {
        cin >> A[i];
        AA[D[i] = lower_bound(AA, AA+siz+1, A[i])-AA] = A[i];
        if(D[i] > siz) ++siz;
    }
    cout << siz;

    return 0;
}