// #include <iostream>
// using namespace std;
// int main() {
//     for (char c : string("abc")) {
//         cout << (int)c << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s; cin >> s;
    bool vowel[26] = {false,};
    for(char c: string("aeiou")) vowel[c-'a'] = true;
    while(s!="#") {
        deque<char> deq;
        for(char c: s) deq.push_back(c);
        for(int i=0,n = deq.size();i<n && !vowel[s[i]-'a'];++i) {
            deq.push_back(deq.front()); deq.pop_front(); 
        }
        deq.push_back('a'); deq.push_back('y');
        for(char c: deq) cout << c;
        cout << '\n';
        cin >> s;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     cin.tie(NULL); ios_base::sync_with_stdio(false);
//     string s; cin >> s;
//     set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
//     while(s!="#") {
//         deque<char> deq;
//         for(char c: s) deq.push_back(c);
//         for(int i=0,n=s.size();i<n && vowel.find(s[i]) == vowel.end();++i) {
//             deq.push_back(deq.front()); deq.pop_front(); 
//         }
//         deq.push_back('a'); deq.push_back('y');
//         for(char c: deq) cout << c;
//         cout << '\n';
//         cin >> s;
//     }
//     return 0;
// }