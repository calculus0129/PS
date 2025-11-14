#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n; string s;
    cin >> n;
    while(n--) {
        cin >> s;
        cout << s.length() << '\n';
    }
    return 0;
}