#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        int m, n; cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i) {
            cin >> arr[i];
        }
        cin >> m;
        map<int,char> mp1;
        map<char,int> mp2;
        while(m--) {
            mp1.clear();
            mp2.clear();
            string s; cin >> s;
            bool r = s.size() == n;
            if(r) for(int i=0;i<n;++i) {
                if(
                    !(
                        (mp1.find(arr[i]) == mp1.end()) && (mp2.find(s[i]) == mp2.end()) ||
                        ((mp1.find(arr[i]) != mp1.end()) && (mp2.find(s[i]) != mp2.end()) && mp1[arr[i]] == s[i] && arr[i] == mp2[s[i]])
                    )

                    ) {
                    r = false;
                    break;
                }
                mp1.insert(make_pair(arr[i], s[i]));
                mp2.insert(make_pair(s[i], arr[i]));
            }
            cout << (r?"YES\n":"NO\n");
        }

    }
    return 0;
}