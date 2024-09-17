#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    set<string> st;
    st.insert("Never gonna give you up");
    st.insert("Never gonna let you down");
    st.insert("Never gonna run around and desert you");
    st.insert("Never gonna make you cry");
    st.insert("Never gonna say goodbye");
    st.insert("Never gonna tell a lie and hurt you");
    st.insert("Never gonna stop");

    int n; cin >> n;
    bool no = false;
    cin.ignore();
    while(n--) {
        string s;
        getline(cin, s);
        no |= st.find(s) == st.end();
    }
    cout << (no?"Yes":"No");
    return 0;
}