#include <bits/stdc++.h>
using namespace std;
set<string> v;

bool matches(char f[3], char s[3]) {
    return abs(f[0]-s[0]) == 1 && abs(f[1]-s[1]) == 2 || abs(f[0]-s[0]) == 2 && abs(f[1]-s[1]) == 1;
}

bool allvisited() {
    return v.size() == 36;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    char first[3], let[3], second[3];
    cin >> let;
    v.insert(string(let));
    bool validity = true;
    memcpy(first, let, sizeof(first));
    while(cin >> second) {
        v.insert(string(second));
        if(!matches(let, second)) {
            validity=false;
            break;
        }
        swap(let, second);
    }
    if(validity) validity = allvisited() && matches(let, first);
    cout << (validity?"Valid":"Invalid");
    return 0;
}