#include <bits/stdc++.h>
using namespace std;

int factorial(int n) {
    if(n==0) return 1;
    return n * factorial(n-1);
}

string work(string s, int n, int step=0) {
    if(n>=factorial(s.size())) return "No permutation";
    if(n==0) return s;
    int fact = factorial(s.size()-1-step), offset = n/fact;
    if(offset==0) return work(s, n, step+1);
    swap(s[step], s[step+offset]);
    for(int i=offset;i>1;--i) swap(s[step+i-1], s[step+i]);
    return work(s, n%fact, step+1);
}
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    int n;
    // https://www.acmicpc.net/board/view/120317
    while(cin >> s) {
        cin >> n;
        cout << s << ' ' << n << " = " << work(s, n-1) << '\n';
    }
    return 0;
}