#include <bits/stdc++.h>
using namespace std;
int n, arr[51];

int find_idx(int v) {
    int mi[51]={arr[0]}, ma[51]={arr[0]};
    for(int i=1;i<n;++i) {
        mi[i] = min(mi[i-1], arr[i]);
        ma[i] = max(ma[i-1], arr[i]);
        if(ma[i]-mi[i]>=v) return i;
    }
    return n;
}

int find_ans(int idx, int v) {
    if(idx == n) return n;
    if((idx&1)==1) {
        return (idx+1)/2+1;
    } else {
        for(int i=0;i<idx;i+=2) {
            if(abs(arr[idx] - arr[i])>=v) return idx/2+1;
        }
        return idx/2+2;
    }
}

int main() {
    int v;
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> v;
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    cout << find_ans(find_idx(v), v);

    return 0;
}


/*typedef long long int LLI;
class matrix {
    public:
    int m, n;
    vector<vector<LLI>> data;
    matrix(matrix& x)
    : m(x.m), n{x.n}, data{x.data} {}
    matrix(int m=0, int n=0, vector<vector<LLI>> data=vector<vector<LLI>>())
    : m(m), n{n}, data{data} {}
    static matrix identity(int n) {
        matrix ret = *(new matrix(n, n, vector<vector<LLI>>(n, vector<LLI>(n, 0LL))));
        for(int i=0;i<n;++i) ret.data[i][i]=1LL;
        return ret;
    }
    matrix& operator=(matrix& other) {
        m = other.m;
        n = other.n;
        data = other.data;
        return *this;
    }
    matrix& operator*(matrix& other) {
        if(n!=other.m) return *(new matrix());
        matrix* ret = new matrix(m, other.n, vector<vector<LLI>>(m, vector<LLI>(other.n, 0LL)));
        for(int i=0, nn=other.n, j, k;i<m;++i) for(j=0;j<nn;j++) for(k=0;k<n;++k) ret->data[i][j] += data[i][k] * other.data[k][j];
        return *ret;
    }
    matrix& operator*=(matrix& other) {
        if(n!=other.m) throw new exception;
        vector<vector<LLI>> dat(m, vector<LLI>(other.n, 0LL));
        for(int i=0, nn=other.n, j, k;i<m;++i) for(j=0;j<nn;j++) for(k=0;k<n;++k) dat[i][j] += data[i][k] * other.data[k][j];
        n = other.n;
        data = dat;
        return *this;
    }
    matrix& operator^(int exp) {
        if(m!=n) throw new exception;
        matrix& ret = *(new matrix(n, n, vector<vector<LLI>>(n, vector<LLI>(n, 0LL)))), m(*this);
        for(int i=0;i<n;++i) ret.data[i][i]=1LL;
        while(exp>0) {
            if((exp&1)==1) ret *= m;
            m*=m;
            exp>>=1;
        }
        return ret;
    }
    string tostring() {
        if(m*n==0) return "[]";
        string ret = "";
        for(int i=0, j;i<m;++i) {
            ret += "[";
            for(j=0;j<n;++j) {
                ret += "\t";
                ret += to_string(data[i][j]);
            }
            ret += "\t]\n";
        }
        return ret;
    }
};

int main() {
    cin.tie(NULL) -> sync_with_stdio(0);
    vector<vector<LLI>> fibo_dat(2, vector<LLI>(2, 1LL));
    fibo_dat[1][1]=0LL;
    matrix iden = matrix::identity(2);
    matrix fibo_mat(2, 2, fibo_dat);
    cout << iden.tostring() << "\n";
    cout << (fibo_mat^50).tostring();
    return 0;
}*/