#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
int main() {
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=n, j;i>=1;--i) {
        deq.push_front(j=i);
        while(j--) {
            deq.push_front(deq.back()); deq.pop_back();
        }
    }
    for(auto i=deq.begin(), e=deq.end();i!=e;++i) {
        cout << *i << ' ';
    }
    return 0;
}