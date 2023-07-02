#include <iostream>
#include <string> // necessary for cin >> s;
#include <list>
using namespace std;
list<char> l;
list<char>::iterator p;

void left() {
    if(p==l.begin()) return;
    --p;
}

void right() {
    if(p==l.end()) return;
    ++p;
}

void backspace() {
    if(p==l.begin()) return;
    p=l.erase(--p); // erase(~): returns the iterator that was next to the erased one.
}

void add(char c) {
    l.insert(p, c); // => yabcdx. This indicates that end()++ == begin()! Circular list!
    // iterator of p is the same, and *p is also same.
    //p=l.insert(p, c); //=> returns the iterator of inserted position
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    int i, m, n;
    cin >> m;
    char c, a;
    for(char c:s) l.push_back(c);
    p=l.end();
    while(m--) {
        cin >> c;
        switch(c) {
            case 'L':
                left();
                break;
            case 'D':
                right();
                break;
            case 'B':
                backspace();
                break;
            case 'P':
                cin >> a;
                add(a);
                break;
        }
    }
    for(char c:l) {
        cout << c;
    }
    return 0;
}