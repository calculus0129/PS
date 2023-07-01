#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(c<b) swap(c, b);
    if(b<a) swap(b, a);
    if(c<b) swap(c, b);
    cout << a << ' ' << b << ' ' << c;
    return 0;
}