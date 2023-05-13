#include <bits/stdc++.h>
using namespace std;
class matrix {
    int m, n;
    vector<vector<int>> arr;
    public:
    //matrix(int m, int n): m(m), n{n}, arr(vector<vector<int>> (m, vector<int> (n))) {}
    matrix(int m, int n, vector<vector<int>>* d) : m{m}, n(n), arr(*d) {}
    matrix XOR(const matrix &other, int px=0, int py=0) const;
    vector<int>& operator[](int i) {return arr[i];}
    bool is_zero();
    //friend ostream& operator<<(ostream& out, const matrix &x);
    friend int work(matrix &x);
};
// We should give the default value of a method ONLY in its prototype.
// In the main body, we should NOT give any default value, since it would fail in compilation if so.
matrix matrix::XOR(const matrix &other, int px, int py) const {
    vector<vector<int>> p = vector<vector<int>>(arr);
    int om=other.m, on=other.n;
    for(size_t i=0, j;i<om;++i) for(j=0;j<on;++j) {
        p[i+px][j+py] ^= other.arr[i][j];
    }
    matrix ret(m, n, &p);
    return ret;
}

bool matrix::is_zero() {
    int ret=0;
    for(size_t i=0, j;i<m;++i) for(j=0;j<n;++j) ret |= arr[i][j];
    return ret==0;
}

/*ostream& operator<<(ostream& out, const matrix &x) {
    out << "matrix with size " << x.m << " * " << x.n << "\n";
    const vector<vector<int>> &vec = x.arr;
    for(int i=0,j;i<x.m;++i) {
        for(j=0;j<x.n;++j) {
            out << vec[i][j] << " ";
        }
        out << "\n";
    }
    out << endl;
    return out;
}*/

int work(matrix &x) {
    int m=x.m-2, n=x.n-2, cnt=0;
    vector<vector<int>> ar(3, vector<int>(3, 1)); // Can't put static or const, since the constructor must specify the parameters as so.
    static const matrix one(3, 3, &ar);
    vector<vector<int>> &arr = x.arr; // arr = x.arr; //=> copied? or pointed? I guess it's copied.
    for(int i=0,j;i<m;++i) for(int j=0;j<n;++j) if(arr[i][j]) {
        ++cnt;
        x = x.XOR(one, i, j);
    }
    return cnt;
}

int main() {
    int m, n;
    cin >> m >> n;
    char buf[51];
    vector<vector<int>> v1(m, vector<int>(n)), v2(m, vector<int> (n));
    for(size_t i=0, j;i<m;++i) {
        cin >> buf;
        for(j=0;j<n;++j) {
            v1[i][j] = buf[j]=='1';
        }
    }
    for(size_t i=0, j;i<m;++i) {
        cin >> buf;
        for(j=0;j<n;++j) {
            v2[i][j] = buf[j]=='1';
        }
    }
    matrix A(m, n, &v1), B(m, n, &v2);
    //cout << A << B;
    matrix C = A.XOR(B);
    //cout << C;
    int c = work(C);
    if(C.is_zero()) {
        cout << c;
    } else {
        cout << -1;
    }

    return 0;
}