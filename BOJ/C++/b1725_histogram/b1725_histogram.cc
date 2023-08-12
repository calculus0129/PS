#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1<<17;
int mintree[SIZE<<1];
int arr[SIZE];

void init() {
    for(int i=16, j, e;i>=0;--i) {
        for(j=1<<i, e = j<<1;j<e;++j) {
            mintree[j] = min(mintree[j<<1], mintree[j<<1|1]);
        }
    }
}

int query(int l, int r, int start=0, int end=SIZE-1, int node=1) {
    if(l <= start && end <= r) return mintree[node];
    if(start > r || end < l) return 1000000001;
    int mid = start + end >> 1;
    return min(query(l, r, start, mid, node<<1), query(l, r, mid+1, end, node<<1|1));
}

int histo(int l, int r) {
    if (l == r) return arr[l];
    int mid = l + r >> 1, i, j; //m = query(l, r);
    int h = min(arr[i=mid], arr[j=mid+1]), ret = h<<1;//max(h<<1, m*(r-l+1));
    --i; ++j;
    while(i>=l || j<=r) {
        if(j>r) {
            h = min(h, arr[i--]);
        }
        else if(i<l || arr[i]<arr[j]) {
            h = min(h, arr[j++]);
        }
        else {
            h = min(h, arr[i--]);
        }
        //if(h==m) break;
        ret = max(ret, h*(j-i-1));
    }
    return max(ret, max(histo(l, mid), histo(mid+1, r)));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    //memcpy(mintree+SIZE, arr, sizeof(int)*n);
    //init();
    cout << histo(0, SIZE-1);
    return 0;
}