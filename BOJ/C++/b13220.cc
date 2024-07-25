#include <bits/stdc++.h>
using namespace std;
vector<int> A,B;

vector<int> failure(const vector<int> &arr) {
    int n = arr.size();
    vector<int> ret(n);
    for(int i=1,j=0;i<n;++i) {
        while(j>0 && arr[i] != arr[j]) j = ret[j-1];
        if(arr[i] == arr[j]) ret[i] = ++j;
    }
    return ret;
}

bool work() {
    A.insert(A.end(), A.begin(), A.end());
    int n = B.size();
    vector<int> fB = failure(B);
    for(int i=0,j=0,e=A.size();i<e;++i) {
        while(j>0 && A[i] != B[j]) j = fB[j-1];
        if(A[i] == B[j] && ++j>=n) return true;
    }
    return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    A.reserve(200020);
    int n; cin >> n;
    A.resize(n); B.resize(n);
    for(int i=0;i<n;++i) cin >> A[i];
    for(int i=0;i<n;++i) cin >> B[i];
    cout << (work()?"YES":"NO");

    return 0;
}