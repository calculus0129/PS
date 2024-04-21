#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int ans=0;
    for(char c: s) if(isvowel(c)) ++ans;
    cout << ans;
    return 0;
}