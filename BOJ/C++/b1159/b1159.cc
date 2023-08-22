#include <bits/stdc++.h>
using namespace std;
int arr[26];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    while(n--) {
        cin >> s;
        arr[s[0]-'a']++;
    }
    string ans;
    for(int i=0;i<26;++i) if(arr[i]>=5) {
        ans += i+'a';
    }
    if(ans=="") {
        ans = "PREDAJA";
    }
    cout << ans;
    return 0;
}