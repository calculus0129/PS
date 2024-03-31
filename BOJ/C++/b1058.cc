#include <bits/stdc++.h>
using namespace std;

class matrix {
public:
    bool data[50][50];
    int n;
    matrix(bool dat[50][50], int n)
    : n{n} {
        for(int i=0, j;i<n;++i) for(j=0;j<n;++j) data[i][j] = dat[i][j];
    }
    matrix(string* s, int n)
    : n(n)
    {
        for(int i=0, j=0;i<n;++i,j=0) for(char c: s[i]) {
            data[i][j++] = (c == 'Y');
        }
    }
    matrix& operator=(const matrix & other) {
        for(int i=0, j;i<n;++i) for(j=0;j<n;++j) data[i][j] = other.data[i][j];
        return *this;
    }

    matrix operator*(const matrix & other) const {
        assert(other.n == n);
        bool dat[50][50];
        for(int i=0;i<n;++i) memset(dat[i], 0, sizeof(dat[i]));
        for(int i=0, j, k;i<n;++i) for(j=0;j<n;++j) for(k=0;k<n;++k) dat[i][j] |= (data[i][k] && other.data[k][j]);
        return *(new matrix(dat, n));
    }

    matrix operator|(const matrix &other) const {
        bool dat[50][50];
        for(int i=0, j;i<n;++i) for(j=0;j<n;++j) dat[i][j] = (data[i][j] || other.data[i][j]);
        return *(new matrix(dat, n));
    }

    matrix& tracer() {
        for(int i=0;i<n;++i) data[i][i] = false;
        return *this;
    }

    int most_friend() {
        int ret = 0;
        for(int i=0, j, cnt;i<n;++i) {
            for(cnt=j=0;j<n;++j) if(data[i][j]) ++cnt;
            if(ret<cnt) ret = cnt;
        }
        return ret;
    }
};
string s[50];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        cin >> s[i];
    }
    matrix m(s, n);
    cout << (m|(m*m)).tracer().most_friend();
    
    return 0;
}