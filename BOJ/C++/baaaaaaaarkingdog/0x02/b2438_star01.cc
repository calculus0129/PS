#include <iostream>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=1, j;i<=n;++i) {
        for(j=0;j<i;++j) cout << '*';
        cout << '\n';
    }
}