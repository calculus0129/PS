#include <bits/stdc++.h>
#define SUM(x,y) ((x)+(y))%BIG
const int BIG = 1000000000;
using namespace std;

// Note: operator precedence: ~ >> shift > ineq > eq > & > ^ > | > && > || > ternary == assignment

int D[101][10][1024]; // D[i][j][k]: 길이가 i, j로 끝나는 k의 이진수 숫자

int idx(int num, int b) {
    int mask = (1<<b) - 1, l = num & mask;
    return (num & ~mask) << 1 | l;
}

void init() {
    for(int i=1;i<10;++i) D[1][i][1<<i]=1;
}

void fill() {
    int num;
    for(int i=2, j, k;i<=100;++i) {
        for(k=0;k<512;++k) {
            D[i][0][k<<1|1] = SUM(D[i-1][1][k<<1], D[i-1][1][k<<1|1]);
        }
        for(j=1;j<9;++j) for(k=0;k<512;++k) {
            num = idx(k, j);
            D[i][j][num|1<<j] = SUM (
                SUM(D[i-1][j-1][num], D[i-1][j-1][num|1<<j]),
                SUM(D[i-1][j+1][num], D[i-1][j+1][num|1<<j]) );
        }
        for(k=0;k<512;++k) {
            num = idx(k, 9);
            D[i][9][num|1<<9] =
                SUM(D[i-1][8][num], D[i-1][8][num|1<<9]);
        }
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    init();
    fill();
    int n, ans = 0; cin >> n;
    for(int i=0;i<10;++i) ans = SUM(ans, D[n][i][1023]);
    cout << ans;
    
    return 0;
}