#include <bits/stdc++.h>
using namespace std;
vector<string> arr, ansarr;

bool overlapping(string s1, string s2) {
    int n1=s1.size(), n2=s2.size();
    if(s1<=s2 && n1<=n2) {
        for(int i=0;i<n1;++i) if(s1[i] != s2[i]) return false;
        return true;
    } else return false;
}

int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    arr.reserve(n);
    ansarr.reserve(n);
    string s;
    while(n--) {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end());
    for(string s: arr) {
        // if(ansarr.empty()) {
        //     ansarr.push_back(s);
        //     continue;
        // }
        auto it = lower_bound(ansarr.begin(), ansarr.end(), s);
        if(it != ansarr.end() && overlapping(s, *it)) continue;
        ansarr.insert(it, s);
        if(it != ansarr.begin() && overlapping(*(it-1), s)) {
            ansarr.erase(it-1);
        }
    }
    cout << ansarr.size();

    return 0;
}