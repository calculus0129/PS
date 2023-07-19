#include <bits/stdc++.h>
using namespace std;
// square matrix
struct matrix {
    size_t siz;
    vector<vector<int>> dat;
};

matrix operator*(const matrix &a, const matrix &b) {
    assert(a.siz == b.siz);
    matrix ret;
    size_t n = a.siz, i, j, k;
    ret.siz = n;
    ret.dat = vector<vector<int>>(n, vector<int>(n, 0));
    for(i=0;i<n;++i) for(j=0;j<n;++j) for(k=0;k<n;++k) ret.dat[i][j] += a.dat[i][k] * b.dat[k][j];
    return ret;
}

matrix operator+(const matrix &a, const matrix &b) {
    assert(a.siz == b.siz);
    int x;
    matrix ret;
    size_t n = a.siz, i, j;
    ret.siz = n;
    ret.dat = vector<vector<int>>(n, vector<int>(n, 0));
    for(i=0;i<n;++i) for(j=0;j<n;++j) ret.dat[i][j] = a.dat[i][j] + b.dat[i][j];
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    size_t n;
    cin >> n;
    //string s;
    char c;
    matrix mat;
    mat.dat = vector<vector<int>>(n, vector<int>(n, 0));
    for(size_t i=0, j;i<n;++i) for(j=0;j<n;++j) {
        cin >> c;
        mat.dat[i][j] = c =='Y';
    }
    mat = mat*mat + mat;
    int ans=0, a;
    for(size_t i=0, j;i<n;++i) {
        a=0;
        for(j=0;j<n;++j) a += mat.dat[i][j];
        if(a>ans) ans = a;
    }
    cout << ans;

    return 0;
}