#include <iostream>
using namespace std;
int main() {
    int w, h;
    cin >> w >> h;
    cout << fixed;
    cout.precision(1);
    cout << w * h / 2.0;
    return 0;
}