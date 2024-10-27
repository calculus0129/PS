#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    double a, b;
    
    cin >> a >> b;
    
    do {
        if(a==0 || b==0) {
            cout << "AXIS\n";
        } else {
            if(a>0 && b>0) cout << "Q1\n";
            else if(a<0 && b>0) cout << "Q2\n";
            else if(a<0 && b<0) cout << "Q3\n";
            else cout << "Q4\n";
        }
        cin >> a >> b;
    } while(a || b);
    cout << "AXIS";
    return 0;
}