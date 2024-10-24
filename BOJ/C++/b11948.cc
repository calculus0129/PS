#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int a[4], b[2], sum=0;
    for(int i=0;i<4;++i) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> b[0] >> b[1];
    sum += b[0] + b[1];
    sum -= *min_element(a, a+4);
    sum -= *min_element(b, b+2);
    cout << sum;

    return 0;
}