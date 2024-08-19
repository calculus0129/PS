#include <bits/stdc++.h>
using namespace std;
#define BIG 1000000007
#define ADD(x, y) ((x+y)%BIG)
#define MUL(x, y) ((x*y)%BIG)
typedef long long ll;

struct Mat {
    int m, n;
    vector<vector<int>> data;
    Mat(int m=1, int n=1)
    : m(m), n(n) {
        data.assign(m, vector<int>(n));
    }
    Mat(vector<vector<int>> data)
    : m(data.size()), n(data[0].size()), data(data) {}
    Mat operator*(const Mat &mat) const {
        assert(n == mat.m);
        vector<vector<int>> res(m, vector<int>(mat.n));
        for(int i=0,j,k;i<m;++i) for(j=0;j<mat.n;++j) {
            int r = 0;
            for(k=0;k<n;++k) r = ADD(r, MUL((ll)data[i][k], (ll)mat.data[k][j]));
            res[i][j] = r;
        }
        return Mat(res);
    }
    Mat operator^(int exponent) {
        assert(m == n);
        vector<vector<int>> ident(m, vector<int>(m));
        for(int i=0;i<m;++i) ident[i][i] = 1;
        Mat mat = *this, ret = Mat(ident);
        while(exponent) {
            if(exponent&1) ret = ret * mat;
            mat = mat * mat;
            exponent>>=1;
        }
        return ret;
    }
};

int fibo(int n) {
    Mat fib({{0,1},{1,1}});
    return ((fib^n)*Mat(vector<vector<int>>({{1}, {1}}))).data[1][0];
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    n-=2;
    cout << fibo(n) << ' ' << n;
    return 0;
}