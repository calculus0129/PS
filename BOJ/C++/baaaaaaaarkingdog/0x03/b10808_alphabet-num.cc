#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[26];
    fill(arr, arr+26, 0);
    string s;
    cin >> s;
    for(char c: s) {
        arr[c-'a']++;
    }
    for(int i=0;i<26;++i) cout << arr[i] << ' ';
    return 0;
}