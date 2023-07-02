#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main() {
    string s;
    cin >> s;
    for(char c: s) {
        arr[c-'a']++;
    }
    for(int i=0;i<26;++i) cout << arr[i] << ' ';
    return 0;
}