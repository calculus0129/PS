#include <bits/stdc++.h>
#define X first
#define Y second
#define BEGIN(x) x.begin()
#define END(x) x.end()
#define ALL(x) BEGIN(x), END(x)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;

int arr[102][102];

void fix(int x, int y) {
    int &a = arr[x][y], b = arr[x-1][y], c = arr[x+1][y], d = arr[x][y+1], e = arr[x][y-1];
    int f = max(max(b, c), max(d, e));
    if(a>f) a = f;
}

void work() {
    memset(arr, 0, sizeof(arr));
    int m, n; cin >> n >> m;
    for(int i=1,j;i<=n;++i) for(j=1;j<=m;++j) cin >> arr[i][j];
    for(int i=1,j;i<=n;++i) for(j=1;j<=m;++j) fix(i, j);
    for(int i=1,j;i<=n;++i) {
        for(j=1;j<=m;++j) cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        work();
    }
    return 0;
}