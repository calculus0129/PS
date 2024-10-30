#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    for(int i=(n>>1)-1;~i;--i) arr[s[i]-'a']++;
    for(int i=n-(n>>1);i<n;++i) arr[s[i]-'a']++;
    bool r = true;
    for(int i=0;i<26;++i) if(arr[i]&1) {
        r = false;
        break;
    }
    cout << (r?"Yes":"No");
    
    return 0;
}