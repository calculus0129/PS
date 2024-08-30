#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
using namespace std;
map<char, char> mir;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    mir['A'] = 'A';
    mir['E'] = '3';
    mir['H'] = 'H';
    mir['I'] = 'I';
    mir['J'] = 'L';
    mir['L'] = 'J';
    mir['M'] = 'M';
    mir['O'] = 'O';
    mir['S'] = '2';
    mir['T'] = 'T';
    mir['U'] = 'U';
    mir['V'] = 'V';
    mir['W'] = 'W';
    mir['X'] = 'X';
    mir['Y'] = 'Y';
    mir['Z'] = '5';
    mir['1'] = '1';
    mir['2'] = 'S';
    mir['3'] = 'E';
    mir['5'] = 'Z';
    mir['8'] = '8';
    string s;
    while(cin >> s) {
        string rev;
        reverse_copy(ALL(s), rev.begin());
        bool pal = true, mirr = true;
        for(int i = 0, n=s.size(); i < n; i++) {
            if(s[i] != rev[i]) pal = false;
            if(mir.find(s[i]) == mir.end() || mir[s[i]] != rev[i]) mirr = false;
        }
        cout << s << " -- is ";
        if(pal && mirr) cout << "a mirrored palindrome.\n\n";
        else if(pal) cout << "a palindrome.\n\n";
        else if(mirr) cout << "a mirrored string.\n\n";
        else cout << "not a palindrome.\n\n";
    }
    return 0;
}