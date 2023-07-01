#include <iostream>
using namespace std;
int main() {
    int n, a, y=0, m=0;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> a;
        y+=1+a/30;
        m+=1+a/60;
    }
    y*=10;
    m*=15;
    if(y<m) cout << "Y " << y;
    else if(y==m) cout << "Y M " << y;
    else cout << "M " << m;
    return 0;
}