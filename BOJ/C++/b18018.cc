#include <bits/stdc++.h>
using namespace std;
map<char, vector<int>> dict;
vector<string> words;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    char start;
    string s;
    cin >> s;
    start = s.back();
    int n; cin >> n;
    words.resize(n);
    for(int i=0;i<n;++i) {
        cin >> s;
        words[i] = s;
        dict[s.front()].push_back(i);
    }
    const vector<int> &candidates = dict[start];
    if(candidates.empty()) cout << "?";
    else {
        int ans = candidates[0];
        bool ext = false;
        if(candidates.size() == 1 && start == words[ans].back()) ext = true;
        else for(int i : candidates) if(dict[words[i].back()].empty()) {
            ans = i;
            ext = true;
            break;
        }
        cout << words[ans] << (ext?"!":"");
    }

    return 0;
}