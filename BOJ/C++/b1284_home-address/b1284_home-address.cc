#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int ans;
    cin >> s;
    while(s.size()!=1 || s[0]!='0') {
        ans=s.size()*4+1;
        for(char i: s) {
            if(i=='0') ++ans;
            else if(i=='1') --ans;
        }
        cout << ans << '\n';
        cin >> s;
    }
    return 0;
}