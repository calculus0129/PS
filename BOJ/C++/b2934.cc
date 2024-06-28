#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int segtree[SIZE<<1];
int lazytree[SIZE<<1];

// Time Complexity: O(1)
void update_lazy(int start, int end, int node) {
    if(lazytree[node]!=0) {
        segtree[node] += (end-start+1) * lazytree[node];
        if(start != end) {
            lazytree[node<<1] += lazytree[node];
            lazytree[node<<1|1] += lazytree[node];
        }
        lazytree[node]=0;
    }
}

// Time Complexity: O(lg n)
void update_interval(int left, int right, int dif, int start=0, int end=SIZE-1, int node=1) {
    if(left <= start && end <= right) {
        lazytree[node]+=dif;
        update_lazy(start, end, node);
        return;
    }
    update_lazy(start, end, node);
    if(end<left || right<start) return;
    int mid = start+end>>1;
    update_interval(left, right, dif, start, mid, node<<1);
    update_interval(left, right, dif, mid+1, end, node<<1|1);
    segtree[node] = segtree[node<<1]+segtree[node<<1|1];
}

// Will only call so that left == right.
int sum(int left, int right, int start=0, int end=SIZE-1, int node=1) {
    update_lazy(start, end, node);
    if(left<=start && end<=right) return segtree[node];
    if(end<left || right<start) return 0;
    int mid = start+end>>1;
    return sum(left, right, start, mid, node<<1) + sum(left, right, mid+1, end, node<<1|1);
}

void query(int a, int b) {
    cout << sum(a, a) + sum(b, b) << '\n';
    update_interval(a, a, -segtree[SIZE+a]);
    update_interval(b, b, -segtree[SIZE+b]);
    update_interval(a+1, b-1, 1);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0, a, b;i<n;++i) {
        cin >> a >> b;
        query(a, b);
    }
    return 0;
}