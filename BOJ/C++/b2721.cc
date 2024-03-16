#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    int trisum[301]={0};
    for(int i=1;i<=300;++i) {
        trisum[i]=trisum[i-1]+i*(i+1)*(i+2)/2;
    }

    while(t--) {
        cin >> n;
        cout << trisum[n] << "\n"; // (n*(n+1)*(n+2)*(n+3))/8
    }
    return 0;
}