#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore(); // Clear the Buffer
    string s;
    while(n--) {
        getline(cin, s, '\n'); // Clear the Buffer. We don't need to clean the buffer again after getline like this.
        if(s[0] >= 'a') {
            s[0] -= 'a'-'A';
        }
        cout << s << '\n';
    }
    return 0;
}