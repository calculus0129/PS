#include <bits/stdc++.h>
using namespace std;
int h1, w1, h2, w2, ans = INT_MAX;
char cur[10][11], make[10][11];

void work(int ridx, int cidx) {
    int cnt=0;
    for(int i=0,j;i<h2;++i) for(j=0;j<w2;++j) if(make[i][j] == 'O' && (i<ridx || j<cidx || i>=ridx+h1 || j>=cidx+w1 || cur[i-ridx][j-cidx] != 'O')) cnt++;
    if(cnt<ans) ans = cnt;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> h1 >> w1;
    cin.ignore();
    for(int i=0;i<h1;++i) {
        cin.getline(cur[i], 11);
    }
    // cout << cur[2] << endl;

    cin >> h2 >> w2;
    cin.ignore();
    for(int i=0;i<h2;++i) {
        cin.getline(make[i], 11);
    }

    for(int i=min(0, 1-h1), j;i<h2;++i) for(j=min(0, 1-w1);j<w2;++j) work(i, j);
    cout << ans;


    return 0;
}