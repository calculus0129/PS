#include <bits/stdc++.h>
#define ALL(a) a.begin(), a.end()
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    // char a[1001], b[1001], c;
    // int la, lb, cnt;
    // while(cin>>a) {
    //     cin >> b;
    //     string s = "";
    //     la = strlen(a), lb = strlen(b);
    //     sort(a, a+la);
    //     sort(b, b+lb);
    //     for(c='a';c<='z';++c) {
    //         cnt = min(upper_bound(a, a+la, c)-lower_bound(a, a+la, c), upper_bound(b, b+lb, c)-lower_bound(b, b+lb, c));
    //         while(cnt--) s += c;
    //         // cout << "a: [" << c << "]: " << upper_bound(a, a+la, c)-lower_bound(a, a+la, c) << '\n';
    //         // cout << "b: [" << c << "]: " << upper_bound(b, b+lb, c)-lower_bound(b, b+lb, c) << '\n';
    //     }
    //     cout << s << '\n';
    // }

    char c;
    int cnt;
    string a, b;
    while(getline(cin,a),getline(cin,b)) {
        string s = "";
        sort(ALL(a));
        sort(ALL(b));
        for(c='a';c<='z';++c) {
            cnt = min(upper_bound(ALL(a), c)-lower_bound(ALL(a), c), upper_bound(ALL(b), c)-lower_bound(ALL(b), c));
            while(cnt--) s += c;
            // cout << "a: [" << c << "]: " << upper_bound(a, a+la, c)-lower_bound(a, a+la, c) << '\n';
            // cout << "b: [" << c << "]: " << upper_bound(b, b+lb, c)-lower_bound(b, b+lb, c) << '\n';
        }
        cout << s << '\n';
    }

    return 0;
}