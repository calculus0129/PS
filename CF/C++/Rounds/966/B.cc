#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    int n, a;
    set<int> s;
    bool r;
    while(t--) {
        s.clear();
        r = true;
        cin >> n;
        cin >> a;
        s.insert(a);
        s.insert(a-1);
        s.insert(a+1);
        for(int i=1;i<n;++i) {
            cin >> a;
            if(s.find(a) == s.end()) {
                r = false;
            }
            s.insert(a);
            s.insert(a-1);
            s.insert(a+1);
        }
        cout << (r?"YES\n":"NO\n");
    }
    return 0;
}