#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001
int n;
// Apply Union-Find algorithm.

// 이 size: 약 4MB
int par[MAX];

// find the root + 'path compression'
// 10만 개 int 하나와 포인터 하나의 stack frame이 최대.
// 이때 추가되는 stack size는 (4+8)*10만 byte == 약 1.2 MB
int find(int x) {
    return (par[x] != x)?par[x] = find(par[x]):x;
}

// No need to use union-by-rank/height necessarily.
void _union(int a, int b) {
    par[b] = a;
}

int main() {
    int a, b, m, r;
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<=n;++i) par[i] = i;
    while(m--) {
        cin >> r >> a >> b;
        if(r) {
            cout << ((find(a) == find(b))?"YES\n":"NO\n");
        } else {
            a = find(a), b = find(b);
            if(a!=b) _union(a, b);
        }
    }
    return 0;
}