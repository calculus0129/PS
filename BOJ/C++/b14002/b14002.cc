#include <bits/stdc++.h>
using namespace std;
int A[1001];

int main() {
    int n, a, i=0, j, D[1001]={0,1,}, siz;
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n;
    while(++i<=n) cin >> A[i];
    for(i=2;i<=n;++i) {
        for(j=1;j<i;++j) {
            if(A[j]<A[i] && D[i]<D[j]) {
                D[i]=D[j];
            }
        }
        ++D[j];
    }
    a = max_element(D+1, D+n+1)-D;
    cout << (siz=D[a]) << '\n'; --siz;
    vector<int> v(1, A[a]);
    for(i=a-1;i>0 && siz;--i) if(D[i] == siz && A[i]<A[a]) {
        v.push_back(A[a=i]); --siz;
    }
    for(auto k = v.rbegin(), e=v.rend();k!=e;++k) cout << *k << ' ';
    return 0;
}