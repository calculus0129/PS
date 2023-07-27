#include <iostream>
using namespace std;

int abs(int x) {
    return x<0?-x:x;
}

int main() {
    int a, b;
    cin >> a >> b;
    a--; b--;
    int dist1, dist2;
    dist1 = abs(b/4-a/4);
    dist2 = abs(b%4-a%4);
    cout << dist1 + dist2;
    return 0;
}