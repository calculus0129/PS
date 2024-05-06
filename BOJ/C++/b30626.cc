#include <bits/stdc++.h>
using namespace std;

bool sensor[360];

void sense(int a, int b) {
    a += 180;
    int lo = a-b;
    int hi = a+b;
    for(int i=lo;i<=hi;++i) {
        sensor[(i+360)%360] = true;
    }
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, a, b; cin >> n;
    while(n--) {
        cin >> a >> b; sense(a, b);
    }
    int ans = 0;
    for(int i=0;i<360;++i) if(sensor[i]) ++ans;
    cout << ans;

    return 0;
}