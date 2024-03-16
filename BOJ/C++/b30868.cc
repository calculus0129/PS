#include <iostream>
using namespace std;
string vote(int c) {
    string ret = "";
    while(c>=5) {
        ret += "++++ ";
        c-=5;
    }
    while(c-->0) ret += '|';
    return ret;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, c;
    for(cin >> n;n-->0;) {
        cin >> c;
        cout << vote(c) << '\n';
    }
    return 0;
}