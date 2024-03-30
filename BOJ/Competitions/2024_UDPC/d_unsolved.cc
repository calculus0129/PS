#include <bits/stdc++.h>
using namespace std;
int m, k;
int arr[200010];
const int BIG = 1<<20;
const bool DEBUG = true;

int mymin(int a, int b) {
    return min(BIG, min(a, b));
}

struct mat {
    int a[2]; // from 0
    int b[2]; // from 1
    // mat operator+(const mat &other) const {
    //     return mat({
    //         { mymin(a[0] + other.a[0], a[1] + other.b[0]), mymin(a[0] + other.a[1], a[1] + other.b[1])},
    //         { mymin(b[0] + other.a[0], b[1] + other.b[0]), mymin(b[0] + other.a[1], b[1] + other.b[1])},
    //     });
    // }
    mat &operator+=(const mat &other) {
        int na[2] = { mymin(a[0] + other.a[0], a[1] + other.b[0]), mymin(a[0] + other.a[1], a[1] + other.b[1])},
            nb[2] = { mymin(b[0] + other.a[0], b[1] + other.b[0]), mymin(b[0] + other.a[1], b[1] + other.b[1])};
        a[0] = na[0];
        a[1] = na[1];
        b[0] = nb[0];
        b[1] = nb[1];
        return *this;
    }
};

mat sampl[200010];

bool mp[2][500010];

void construct_mp(const string &s0, const string &s1) {
    int idx=1;
    for(char c: s0) {
        mp[0][idx++]=(c=='#');
    }
    idx = 1;
    for(char c: s1) {
        mp[1][idx++]=(c=='#');
    }
}

int ride(int s, int e, int size) {
    if(mp[s][1] || mp[e][size]) {
        if(DEBUG) cout << "못가네...\n";
        return BIG;
    }
    int ret = 0, i=s, j=0;
    while(j<size) {
        while(j<size && mp[i][j+1]==0) {
            if(DEBUG) cout << "직진!\n";
            ++j;
            ++ret;
        }
        if(j==size) break;
        if(mp[i^1][j] || mp[i^1][j+1]) {
            if(DEBUG) cout << "못가네...\n";
            return BIG;
        }
        else {
            if(DEBUG) cout << "충돌위험! 차선변경 후 직진!\n";
            i^=1;
            ++j;
            ret+=2;
        }
    }
    if(i!=e) {
        if(DEBUG) cout << "차선변경\n";
        i^=1;
        ++ret;
    }
    return ret;
}

void work(mat &target, const string &s0, const string &s1) {
    int n = s0.size();
    // if(DEBUG) cout << s0.size() << " is the size\n";
    construct_mp(s0, s1);
    target.a[0] = ride(0, 0, n);
    target.a[1] = ride(0, 1, n);
    target.b[0] = ride(1, 0, n);
    target.b[1] = ride(1, 1, n);
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    
    cin >> m >> k;
    for(int i=1;i<=k;++i) cin >> arr[i];
    sampl[0] = mat({
        {-1,-1},
        {-1,-1},
    });
    string s0, s1;
    for(int i=1;i<=m;++i) {
        cin >> s0;
        cin >> s1;
        work(sampl[i], s0, s1);

        if(DEBUG) cout << sampl[i].a[0] << ' ' << sampl[i].a[1] << '\n' << sampl[i].b[0] << ' ' << sampl[i].b[1];
        if(DEBUG) cout << '\n';
    }
    if(DEBUG) cout << '\n';
    for(int i=1;i<=k;++i) {
        sampl[0] += sampl[arr[i]];
    }
    if(DEBUG) cout << sampl[0].a[0] << ' ' << sampl[0].a[1] << '\n' << sampl[0].b[0] << ' ' << sampl[0].b[1] << "\n\n";
    int ans = min(min(sampl[0].a[0], sampl[0].a[1]), min(sampl[0].b[0], sampl[0].b[1]));
    cout << ( ans>= BIG?-1:ans);

    return 0;
}