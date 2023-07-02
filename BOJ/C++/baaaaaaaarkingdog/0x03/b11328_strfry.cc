#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, arr[26]={};
    bool r;
    string s1, s2;
    cin >> n;
    while(n--) {
        r=1;
        cin >> s1 >> s2;
        if(s1.size()!=s2.size()) cout << "Impossible\n";
        else {
            for(char c:s1) {
                arr[c-'a']++;
            }
            for(char c:s2) {
                arr[c-'a']--;
            }
            for(int &i:arr) {
                if(i) {
                    r=0;
                    i=0;
                }
            }
            cout << (r?"Possible\n":"Impossible\n");
        }
    }
    return 0;
}