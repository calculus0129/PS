#include <iostream>
using namespace std;
int max(const int &a, const int &b) {
    return (a<b)?b:a;
}
int main() {
    int a, b, c, price;
    cin >> a >> b >> c;
    if(a==b || b==c || c==a) {
        if(a==b && b==c) {
            price=10000+a*1000;
        }
        else {
            price=1000;
            if(a==b) price+=100*a;
            else price+=100*c;
        }
    }
    else {
        price = 100*max(a, max(b, c));
    }
    cout << price;
    return 0;
}