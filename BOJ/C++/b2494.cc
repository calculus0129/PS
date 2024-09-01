#include <bits/stdc++.h>
using namespace std;
vector<int> Prev(10);
vector<vector<int>> turns;

int ldist(char from, char to) {
    from -= '0', to -= '0';
    int ret = 0;
    while(from % 10 != to) {
        from++;
        ret++;
    }
    return ret;
}

int rdist(char from, char to) {
    from -= '0'-10, to -= '0';
    int ret = 0;
    while(from % 10 != to) {
        from--;
        ret++;
    }
    return ret;
}

char turn(char from, int dist) {
    return (from - '0' + dist + 10) % 10 + '0';
}

int main() {
    int n, ld, rd;
    string w, s;
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> n;
    turns.resize(n+1, vector<int>(10, 0));
    cin >> w >> s;
    for(int i=0;i<10;++i) {
        ld = ldist(i+'0', s[n-1]);
        rd = rdist(i+'0', s[n-1]);
        Prev[i] = abs(turns[n][i] = (ld < rd ? ld : -rd));
    }
    for(int i=1,j;i<n;++i) {
        vector<int> cur(10, 0);
        char s0 = s[n-1-i];
        char w0 = w[n-1-i], w1 = w[n-i];
        char real;
        for(j=0;j<10;++j) {
            real = turn(w1, ldist(w0, j+'0'));
            ld = ldist(j+'0', s0);
            rd = rdist(j+'0', s0);
            turns[n-i][j] = (ld + Prev[turn(real, ld)-'0'] < rd + Prev[real-'0'] ? ld : -rd);
            cur[j] = min(ld + Prev[turn(real, ld)-'0'], rd + Prev[real-'0']);
        }
        Prev = cur;
    }
    vector<int> ans(n+1);
    cout << Prev[w[0]-'0'] << '\n';
    int last = max(0, ans[1] = turns[1][w[0]-'0']);
    for(int i=2;i<=n;++i) {
        last += max(0, ans[i] = turns[i][turn(w[i-1], last)-'0']);
    }
    for(int i=1;i<=n;++i) {
        cout << i << ' ' << ans[i] << '\n';
    }
    return 0;
}