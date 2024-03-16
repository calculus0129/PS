#include <bits/stdc++.h>
using namespace std;
char arr[10][11];
int ans = -1, m, m2;

bool is_square(int n) {
    int b = sqrt(n);
    return n == b*b;
}

int num(const char *s, int n) {
    int ret = 0;
    for(int i=0;i<n;++i) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int rev_num(const char *s, int n) {
    int ret = 0;
    for(int i=n-1;i>=0;--i) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

void update(int n) {
    if(is_square(n) && ans < n) ans = n;
}

void update_str(const char *s, int n) {
    update(s[0]-'0');
    for(int i=2;i<=n;++i) {
        update(num(s, i));
        update(rev_num(s, i));
    }
}

int fill_str(int ix, int iy, int sx, int sy, char *dst) {
    if(sx == 0 && sy == 0) {
        *dst = arr[ix][iy];
        return 1;
    }
    int cnt = 0;
    while(ix>=0 && iy>=0 && ix<m && iy<m2) {
        dst[cnt++] = arr[ix][iy];
        ix += sx;
        iy += sy;
    }
    return cnt;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int i=0, j, si, sj, siz;
    cin >> m >> m2;
    cin.ignore(); // remove the remaining '\n' in the input buffer.
    for(;i<m;++i) {
        cin.getline(arr[i], m2+1);
    }
    // for(i=0;i<m;++i) cout << arr[i] << endl;
    char buf[11];
    for(i=0;i<m;++i) for(j=0;j<m2;++j) for(si=0;si+i<m;++si) for(sj=-j;sj+j<m2;++sj) {
        memset(buf, 0, 11);
        siz = fill_str(i, j, si, sj, buf);
        update_str(buf, siz);
    }
    cout << ans;

    return 0;
}