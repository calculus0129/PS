#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d;
    d=b*c;
    cin >> a >> b >> c;
    a*=b*=c;
    // assert(b==d); //Assertion Failed.
    // This indicates that a*=b*=c; is equivalent to (a*=b)*=c;
    int arr[10];
    fill(arr, arr+10, 0);
    for(int i;a!=0;a/=10) {
        i=a%10;
        arr[i]++;
    }
    for(int i=0;i<10;++i) cout << arr[i] << '\n';

    return 0;
}