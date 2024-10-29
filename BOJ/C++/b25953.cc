#include <bits/stdc++.h>
int n;
const int INF=100'000'000;
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T, m, s, e;
    cin >> n >> T >> m;
    vector<int> a1(n, INF), a2(n, INF);
    cin >> s >> e;
    a1[s] = a2[s] = 0;
    while(T--) {
        for(int i=0, a, b, c;i<m;++i) {
            cin >> a >> b >> c;
            if(a1[a] > a1[b]) {
                swap(a, b);
            }
            if(a1[a] + c < a2[b]) a2[b] = a1[a] + c;
        }
        a1 = a2;
    }
    cout << ((a1[e]^INF)?a1[e]:-1);

    return 0;
}