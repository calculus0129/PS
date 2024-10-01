#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int k;

int qPartition(int l, int r) {
    int x = arr[r];
    int i = l-1;
    for(int j=l;j<r && k;++j) {
        if(arr[j]<=x) {
            swap(arr[++i], arr[j]);
            --k;
        }
    }
    if(k && i+1!=r) {
        swap(arr[i+1], arr[r]);
        --k;
    }
    return i+1;
}

void quicksort(int l, int r) {
    if(l<r) {
        int q = qPartition(l, r);
        if(!k) return;
        quicksort(l, q-1);
        quicksort(q+1, r);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n >> k;
    arr.resize(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    quicksort(0, n-1);
    if(k) cout << -1;
    else for(int a: arr) cout << a << ' ';

    return 0;
}