#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int a, b, c;
    while(t--) {
        cin >> a >> c >> b;
        cout << (a+b-(b>>1) > (b>>1)+c?"First\n":"Second\n");
    }
    return 0;
}