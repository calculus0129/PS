#include <bits/stdc++.h>
using namespace std;
set<int> A, B;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int na, nb; cin >> na >> nb;
    for(int i=0, a;i<na;++i) {
        cin >> a;
        A.insert(a);
    }
    for(int i=0, a;i<nb;++i) {
        cin >> a;
        A.erase(a);
    }
    cout << A.size() << '\n';
    for(int a: A) cout << a << ' ';

    return 0;
}