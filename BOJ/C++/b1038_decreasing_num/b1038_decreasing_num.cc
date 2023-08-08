#include <bits/stdc++.h>
using namespace std;

vector<string> vec;

int combo(int r, int n=10) {
    if(n * r == 0 || n == r) return 1;
    return combo(r-1, n-1) + combo(r, n-1);
}

void operation(int step) {
    if(step==0) return;
    vector<string> newvec;
    for(string const &s: vec) {
        for(char j=s[0]+1;j<='9';++j) {
            newvec.push_back(j+s);
        }
    }
    sort(newvec.begin(), newvec.end());
    vec = newvec;
    operation(step-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    ++n;
    if(n>=1<<10) {
        cout << -1;
        return 0;
    }
    int i=1, c = combo(i);
    while(n>c) {
        n -= c;
        c = combo(++i);
    }
    vec = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    operation(i-1);
    cout << vec[n-1];

    
    return 0;
}