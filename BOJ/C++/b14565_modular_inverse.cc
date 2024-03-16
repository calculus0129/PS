#include <bits/stdc++.h>
#define EUCREM(a,b) ((a) < 0LL ? (((b) + (a)%(b))%(b)) : ((a) % (b)))
typedef long long lli;
using namespace std;

class vec {
public:
    int dim;
    lli comp[5];
    vec() : dim(2) {}
    vec(lli a, lli b)
    : dim(2) {
        comp[0]=a;
        comp[1]=b;
    }
    vec(lli *arr, int dim)
    : dim(dim) {
        for(int i=0;i<dim;++i) comp[i] = arr[i];
    }
    // negation
    vec operator-() const {
        lli ncomp[5] = {};
        for(int i=0;i<dim;++i) ncomp[i] = -comp[i];
        return *(new vec(ncomp, dim));
    }
    // scalar multiplication
    vec operator*(lli c) const {
        lli ncomp[5] = {};
        for(int i=0;i<dim;++i) ncomp[i] = c*comp[i];
        return *(new vec(ncomp, dim));
    }
    // addition
    vec operator+(const vec &v) const {
        assert(dim == v.dim);
        lli newcomp[5] = {0LL};
        for(int i=0;i<dim;++i) newcomp[i] = comp[i] + v.comp[i];
        return *(new vec(newcomp, dim));
    }
    // subtraction
    vec operator-(const vec &v) const {
        assert(dim == v.dim);
        lli newcomp[5] = {0LL};
        for(int i=0;i<dim;++i) newcomp[i] = comp[i] - v.comp[i];
        return *(new vec(newcomp, dim));
    }
    // inner product
    lli operator*(const vec& v) const {
        assert(dim == v.dim);
        lli ret = 0LL;
        for(int i=0;i<dim;++i) ret += comp[i] * v.comp[i];
        return ret;
    }
    vec& operator=(const vec &v) {
        dim = v.dim;
        for(int i=0;i<dim;++i) comp[i] = v.comp[i];
        return *this;
    }

};

lli eea(lli a, lli m) {
    lli r[66] = {m, a%m,}, q[66] = {0LL};
    int n=1;
    while(r[n]>0LL) {
        q[n] = r[n-1]/r[n];
        r[n+1] = r[n-1]%r[n];
        ++n;
    }
    --n;
    if(r[n]!=1LL) return -1LL; // when gcd(a, m)>1
    // cout << "\nr: " << r[0] << ' ' << r[1] << " q: " << q[1] << '\n';
    vec p(m, a), v[3];
    v[0] = vec(1LL, 0LL);
    v[1] = vec(0LL, 1LL);
    if(n<=1) return EUCREM(v[n].comp[1], m); // e.g. case when a == 1
    for(int i=1;i<n;++i) {
        v[2] = v[0] - (v[1] * q[i]);
        v[0] = v[1];
        v[1] = v[2];
    }
    return EUCREM(v[2].comp[1], m);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli a, m;
    cin >> m >> a;
    cout << m-a << ' ' << eea(a, m);

    return 0;
}