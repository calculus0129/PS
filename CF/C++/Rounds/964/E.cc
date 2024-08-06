#include <bits/stdc++.h>
using namespace std;
int f(int x) {
    return floor(log2(x)/log2(3)) + 1;
}
int sumf[201010];
void init() {
    for(int i=1;i<=200000;++i) {
        sumf[i] = sumf[i-1] + f(i);
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a, b, t; cin >> t;
    init();
    while(t--) {
        cin >> a >> b;
        cout << sumf[b] - 2*sumf[a-1] + sumf[a] << '\n';
    }

    return 0;
}